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
    /// Interaction logic for Create_Room.xaml
    /// </summary>
    public partial class Create_Room : Page
    {
        Communicator c;
        string _roomName;
        double _players;
        double _questions;
        double _time;

        public Create_Room(Communicator comm)
        {
            InitializeComponent();
            c = comm;
        }

        private void Back_Click(object sender, RoutedEventArgs e)
        {
            this.NavigationService.GoBack();
        }

        private void Send_Click(object sender, RoutedEventArgs e)
        {
            _roomName = RoomNameInput.Text;
 
            _players = Players.Value;
            _questions = Questions.Value;
            _time = Time.Value;

            Console.WriteLine(_roomName + " " + _players.ToString() + " " + _questions.ToString() + " " + _time.ToString());
            //MessageBox.Show(_roomName + " " + _players.ToString() + " " + _questions.ToString() + " " + _time.ToString());
        }

    }
}
