using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using Newtonsoft.Json;
//using System.Text.Json;
using System.Text.Json;

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
