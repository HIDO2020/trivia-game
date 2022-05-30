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
        string _roomName;

        public Create_Room()
        {
            InitializeComponent();
        }

        private void Back_Click(object sender, RoutedEventArgs e)
        {
            this.NavigationService.GoBack();
        }

        private void Send_Click(object sender, RoutedEventArgs e)
        {
            _roomName = RoomNameInput.Text;
            Console.WriteLine(_roomName);
        }

    }
}
