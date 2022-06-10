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
    /// Interaction logic for RoomJoin.xaml
    /// </summary>
    public partial class RoomJoin : Page
    {
        string adminName = "##";
        public RoomJoin()
        {
            InitializeComponent();
            WaitingAdmin.Content = "Waiting For" + adminName + "To Start..";
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
