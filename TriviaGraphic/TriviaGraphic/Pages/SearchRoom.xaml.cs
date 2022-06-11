using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
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
    /// Interaction logic for SearchRoom.xaml
    /// </summary>
    public partial class SearchRoom : Page
    {
        string req;
        string answer;
        int id = 0;
        string _ID;

        Communicator c = new Communicator();

        private void Room_Clicked(object sender, RoutedEventArgs e)
        {
            var myValue = ((Button)sender).Tag;
            id = Int32.Parse((string)myValue); 
            //MessageBox.Show(id.ToString());
            GetPlayersInRoomRequest log = new GetPlayersInRoomRequest { id = id };
            req = c.getPlayersSe(log);
            //MessageBox.Show(req);
            answer = c.getData(req);
            MessageBox.Show(answer);
            //List<string> result = answer.Split('"')
            //        .Select((element, index) => index % 2 == 0  // If even index
            //                              ? element.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)  // Split the item
            //                              : new string[] { element })  // Keep the entire item
            //        .SelectMany(element => element).ToList();
        }

        public SearchRoom(Communicator comm)
        {
            InitializeComponent();
            c = comm;
            req = c.GetRooms();
            //MessageBox.Show(req);
            answer = c.getData(req);
            //MessageBox.Show(answer);
            List<string> result = answer.Split('"')
                    .Select((element, index) => index % 2 == 0  // If even index
                                          ? element.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)  // Split the item
                                          : new string[] { element })  // Keep the entire item
                    .SelectMany(element => element).ToList();

            List<Button> items = new List<Button>();
            for (int i = 5; i < result.ToArray().Length; i += 6)
            {
                _ID = result[i - 3].Remove(0, 1);
                _ID = _ID.Remove(_ID.Length - 1);
                var btn1 = new Button { Content = result[i] };
                btn1.FontSize = 18;
                btn1.Click += Room_Clicked;
                btn1.Tag += _ID;
                items.Add(btn1);
            }
            RoomsList.ItemsSource = items;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.NavigationService.GoBack();
        }

        private void Refresh(object sender, RoutedEventArgs e)
        {
            SearchRoom here = new SearchRoom(c);
            this.NavigationService.Navigate(here);
        }

        private void JoinRoom(object sender, RoutedEventArgs e)
        {
            if (id == 0)
                MessageBox.Show("Select Room");
            else
            {
                RoomJoin RoomPage = new RoomJoin(c, id);
                this.NavigationService.Navigate(RoomPage);
            }
        }
    }
}
