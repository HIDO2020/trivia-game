﻿using System;
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
    /// Interaction logic for ConnectUser.xaml
    /// </summary>
    public partial class ConnectUser : Page
    {
        string username;
        string password;

        public ConnectUser()
        {
            InitializeComponent();
        }

        private void login_click(object sender, RoutedEventArgs e)
        {
            username = UsernameInput.Text;
            password = PasswordInput.Password;
            Console.WriteLine(username + " " + password);

            //Communicator(username, password);

            //MessageBox.Show(username + " " + password);
            Home HomePage = new Home();
            this.NavigationService.Navigate(HomePage);
        }

        private void signup_click(object sender, RoutedEventArgs e)
        {

            Register registerPage = new Register();
            this.NavigationService.Navigate(registerPage);
        }
    }
}
