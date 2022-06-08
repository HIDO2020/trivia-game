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
    /// Interaction logic for Register.xaml
    /// </summary>
    public partial class Register : Page
    {
        Communicator c = new Communicator();
        string username;
        string password;
        string email;
        string req;

        public Register()
        {
            InitializeComponent();
        }

        private void signup_click(object sender, RoutedEventArgs e)
        {
            username = _Username.Text;
            password = _Password.Password;
            email = _Email.Text;

            SignupRequest log = new SignupRequest { username = username, password = password, email = email};

            req = c.RegisterSe(log);
            MessageBox.Show(req);

            Console.WriteLine(username + " " + password + " " + email);
            //MessageBox.Show(username + " " + password + " " + email);
            Home HomePage = new Home();
            this.NavigationService.Navigate(HomePage);
        }

        private void back_click(object sender, RoutedEventArgs e)
        {
            this.NavigationService.GoBack();
        }
    }
}
