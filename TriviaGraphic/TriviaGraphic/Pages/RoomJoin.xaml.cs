using System;
using System.Collections.Generic;
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

        public void updateData()
        {
            while (true)
            { 
                answer = c.getData(req);

                List<string> result = answer.Split('"')
                    .Select((element, index) => index % 2 == 0  // If even index
                                  ? element.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)  // Split the item
                                  : new string[] { element })  // Keep the entire item
                    .SelectMany(element => element).ToList();

                adminName = result[0];
                Dispatcher.Invoke(new Action(() => { }), WaitingAdmin.Content = "Waiting For " + adminName + " To Start.."); 
                List<Label> items = new List<Label>();
                for (int i = 0; i < result.Count(); i += 2)
                {
                    var user = new Label { Content = result[i] };
                    user.FontSize = 18;
                    items.Add(user);
                }
                Dispatcher.Invoke(new Action(() => { }), Players_List.ItemsSource = items);

                
                System.Threading.Thread.Sleep(3000);        //wait 3 sec..
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
            /*
                Fix Thread
            */
            //Thread ts1 = new Thread(updateData);
            //ts1.SetApartmentState(ApartmentState.STA);
            //ts1.Start();

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
