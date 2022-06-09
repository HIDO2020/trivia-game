using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGraphic
{
    class GLOBALS
    {
        private static Communicator comm = new Communicator();

        public static Communicator f_comm
        {
            get { return f_comm; }
            set { f_comm = value; }
        }
    }
}
