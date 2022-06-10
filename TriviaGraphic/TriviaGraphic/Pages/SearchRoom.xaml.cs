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
        Communicator c = new Communicator();

        public SearchRoom(Communicator comm)
        {
            InitializeComponent();
            c = comm;
            req = c.GetRooms();
            MessageBox.Show(req);
            answer = c.getData(req);
            MessageBox.Show(answer);
            var result = answer.Split('"')
                    .Select((element, index) => index % 2 == 0  // If even index
                                          ? element.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)  // Split the item
                                          : new string[] { element })  // Keep the entire item
                    .SelectMany(element => element).ToList();
            
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.NavigationService.GoBack();
        }
    }
}
