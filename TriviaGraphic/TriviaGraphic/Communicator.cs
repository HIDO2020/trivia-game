using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using Newtonsoft.Json;
//using System.Text.Json;
using System.Text.Json;
using System.Net.Sockets;
using System.Net;

namespace TriviaGraphic
{
    enum codes { Error_, signup_, login_, logout_, join_, create_, getRoom_, getPlayers_, getHighScore_, getPersonalStats_ };

    struct SignupRequest
    {
        public string _username { get; set; }
        public string _password { get; set; }
        public string _email { get; set; }
    };

    struct LoginRequest
    {
        public string _username { get; set; }
        public string _password { get; set; }
    }



    class Communicator
    {
        NetworkStream _stream;
        Communicator()
        {
            TcpClient client = new TcpClient();
            IPEndPoint serverEndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 8826);
            client.Connect(serverEndPoint);
            NetworkStream clientStream = client.GetStream();
            this._stream = clientStream;
        }

        public bool handleCommunicate(string req)
        {
            byte[] buffer = new ASCIIEncoding().GetBytes("Hello Server!");
            this._stream.Write(buffer, 0, buffer.Length);
            this._stream.Flush();
            buffer = new byte[4096];



            return true;
        }

        public string LoginSe(LoginRequest log)
        {
            int code = (int)codes.login_;
            var loginRequest = new LoginRequest
            {
                _username = log._username,
                _password = log._password
            };
            string jsonString = JsonSerializer.Serialize<LoginRequest>(loginRequest);
            //return jsonString;
            return helper(jsonString, code);
        }

        public string RegisterSe(SignupRequest log)
        {
            int code = (int)codes.signup_;
            var signupRequest = new SignupRequest
            {
                _username = log._username,
                _password = log._password,
                _email = log._email
            };
            string jsonString = JsonSerializer.Serialize<SignupRequest>(signupRequest);
            //return jsonString;
            return helper(jsonString, code);
        }

        public string helper(string j, int code)
        {
            string res = "";
            res += code.ToString();
            int size = j.Length;
            res += size.ToString();
            while (res.Length < 5)
                res += 0;
            res += j;
            return res;
        }
    }
}
