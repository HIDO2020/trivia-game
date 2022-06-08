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
        public string username { get; set; }
        public string password { get; set; }
        public string email { get; set; }
    };

    struct LoginRequest
    {
        public string username { get; set; }
        public string password { get; set; }
    }



    class Communicator
    {
        NetworkStream _stream;
        public Communicator()
        {
            TcpClient client = new TcpClient();
            IPEndPoint serverEndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 8826);
            client.Connect(serverEndPoint);
            NetworkStream clientStream = client.GetStream();
            this._stream = clientStream;
            byte[] buffer = new ASCIIEncoding().GetBytes("hello");
            this._stream.Write(buffer, 0, buffer.Length);
            this._stream.Flush();
            buffer = new byte[4096];
        }

        public bool handleCommunicate(string req)
        {
            Console.WriteLine(req);
            byte[] buffer = new ASCIIEncoding().GetBytes(req);
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
                username = log.username,
                password = log.password
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
                username = log.username,
                password = log.password,
                email = log.email
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
