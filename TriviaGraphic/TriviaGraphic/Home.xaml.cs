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
    /// Interaction logic for Home.xaml
    /// </summary>
    public partial class Home : Page
    {
        public Home()
        {
            InitializeComponent();
        }

        private void Create_Room_Click(object sender, RoutedEventArgs e)
        {
            Create_Room CreateRoomPage = new Create_Room();
            this.Content = CreateRoomPage;
        }

        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            //this.Close();
        }

        private void stats_Click(object sender, RoutedEventArgs e)
        {
            Statistics StatisticsPage = new Statistics();
            this.Content = StatisticsPage;
        }

        private void records_click(object sender, RoutedEventArgs e)
        {
            Records RecordsPage = new Records();
            this.Content = RecordsPage;
        }
    }
}
