using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGraphic
{
    class GLOBALS
    {
        //private static Communicator _comm = new Communicator();
        //private static NetworkStream _stream;

        //public static NetworkStream stream
        //{
        //    get
        //    {
        //        return _comm.getStream();
        //    }
        //    set
        //    {
        //        stream = value;
        //    }
        //}
        private static Communicator comm = new Communicator();

        public static Communicator f_comm
        {
            get { return f_comm; }
            set { f_comm = value; }
        }


    }
}
