using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TriviaGraphic
{
    /// <summary>
    /// Interaction logic for RoomJoin.xaml
    /// </summary>
    public partial class RoomJoin : Page
    {
        string req;
        string answer;
        string adminName = "##";
        Communicator c;
        List<Label> items = new List<Label>();
        private BackgroundWorker background_worker = new BackgroundWorker();
        string[] _names = new string[9];


        void background_worker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled)
            {
                MessageBox.Show("BackgroundWorker canceled");
            }
            else
            {
                MessageBox.Show("BackgroundWorker ended successfully");
            }
        }


        void background_worker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            int i = 0;
            while (i < _names.Length)
            {
                var user = new Label { Content = _names[i] };
                user.FontSize = 18;
                items.Add(user);
                i++;
            }
            Players_List.ItemsSource = items;
            WaitingAdmin.Content = "Waiting For " + adminName + " To Start..";
        }


        void updateData(object sender, DoWorkEventArgs e)
        {
            Thread.Sleep(3000);        //wait 10 sec..
            int i = 0;
            int j = 0;
            while (true)
            {
                if (background_worker.CancellationPending)
                {
                    e.Cancel = true;
                    break;
                }
                answer = c.getData(req);
                //MessageBox.Show(answer);
                List<string> result = answer.Split('"')
                    .Select((element, index) => index % 2 == 0  // If even index
                                  ? element.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)  // Split the item
                                  : new string[] { element })  // Keep the entire item
                    .SelectMany(element => element).ToList();

                adminName = result[0];

                while (i < result.Count())
                {
                    _names[j] = result[i];
                    i += 2;
                    j++;
                }
                //Players_List.ItemsSource = items;
                background_worker.ReportProgress(_names.Length);
                Thread.Sleep(10000);        //wait 10 sec..
            }

        }

        public RoomJoin(Communicator comm, int id)
        {
            InitializeComponent();
            c = comm;
            //WaitingAdmin.Content = "Waiting For" + adminName + "To Start..";

            GetPlayersInRoomRequest log = new GetPlayersInRoomRequest { id = id };
            req = c.getPlayersSe(log);
            MessageBox.Show(req);


            //Thread ts1 = new Thread(updateData);
            //ts1.SetApartmentState(ApartmentState.STA);
            //ts1.Start();
            background_worker.ProgressChanged += background_worker_ProgressChanged;
            background_worker.DoWork += updateData;
            background_worker.RunWorkerCompleted += background_worker_RunWorkerCompleted;

            background_worker.RunWorkerAsync();
            background_worker.WorkerSupportsCancellation = true;
            background_worker.WorkerReportsProgress = true;

            //MessageBox.Show("tryyyy");
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            /*
             Leave Room Request
             */
            this.NavigationService.GoBack();
        }

    }
}
