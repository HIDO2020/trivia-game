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
        int _players;
        int _questions;
        int _time;
        string req;

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
            _players = (int)Players.Value;
            _questions = (int)Questions.Value;
            _time = (int)Time.Value;

            //Console.WriteLine(_roomName + " " + _players.ToString() + " " + _questions.ToString() + " " + _time.ToString());
            MessageBox.Show(_roomName + " " + _players.ToString() + " " + _questions.ToString() + " " + _time.ToString());
            CreateRoomRequest log = new CreateRoomRequest { roomName = _roomName, maxUsers = _players, questionCount = _questions, answerTimeout = _time };
            req = c.CreateRoomSe(log);
            if (c.handleCommunicate(req))
            {
                Room roomPage = new Room();
                this.NavigationService.Navigate(roomPage);
            }
        }

    }
}
