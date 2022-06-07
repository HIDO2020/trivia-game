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
    //struct SignupRequest
    //{
    //    string username;
    //    string password;
    //    string email;
    //};

    struct LoginRequest
    {
        public string _username { get; set; }
        public string _password { get; set; }
    }



    class Communicator
    {
        
        public string LoginSe(LoginRequest log)
        {
            var loginRequest = new LoginRequest
            {
                _username = log._username,
                _password = log._password
            };
            string jsonString = JsonSerializer.Serialize<LoginRequest>(loginRequest);
            return jsonString;
            //return helper(j, code);
        }

        //public string helper(json j, int code)
        //{
        //    //unsigned char zer = '0';
        //    std::vector < unsigned char> res;
        //    res.push_back((unsigned char)code);
        //    std::string str_res = j.dump();

        //    int size = str_res.size();
        //    /*std::string size = std::to_string(str_res.size());
        //    for (int i = 0; i < size.size(); i++)
        //        res.push_back(size[i]);*/
        //    res.push_back(size);
        //    while (res.size() < 5)
        //        res.push_back(NULL);

        //    res.insert(res.end(), str_res.begin(), str_res.end());
        //    return res;
        //}
    }
}
