#include "Socket.h"


// #define PORT 1500
#define PORT 80
// const string dest_server = "localhost";
// const string dest_server = "127.0.0.1";
// const string dest_server = " 0000:0000:0000:0000:0000:0000:0000:0001"; // localhost in ipv6 // Funktioniert noch nicht
// const string dest_server = "www.wenpas.com";
const string dest_server = "wenpas.ch";




// Client vom Buch C++ von A bis Z und zwar mit selbstgeschriebener Klasse
int client_3(int argc, char** argv)
{
    Sleep(20);
    cout << endl << "Start Client!" << endl;

    int internet_family = AF_INET;
    if (Socket::is_ip6(dest_server)) {
        internet_family = AF_INET6;
    }

    try {
        Socket sock("Client", internet_family);
        sock.create();

        // Adresse des Servers
        string server_addr = dest_server; //  94.126.18.110

        // Mit dem Server verbinden
        bool r_conn = sock.connect(server_addr, PORT);

        // string new_line = "\r\n";
        string new_line = "\n"; // Mit diesem String richtige Antwort von wenpas.ch bekommen

        // Nachricht an den Server
        string msg_to_server = "GET / HTTP/1.1" + new_line;
        msg_to_server += "Host: " + server_addr + new_line; 
        msg_to_server += "User Agent: Internet Explorer" + new_line;
        msg_to_server += (new_line + new_line);

        cout << endl << "Client: msg an Server: " << msg_to_server;

        string msg_from_server = "";

        sock << msg_to_server; // Client sendet
        sock >> msg_from_server; // Cleint bekommt Antwort vom Server
        cout << endl << "Client: Antwort bekommen: " << msg_from_server;
        return 0;
    }
    catch (SocketException& e) {
        cout << endl << "Client: " << e.what();
    }
    catch (exception& e) {
        cout << endl << "Clien: " << e.what();
    }
    catch (...) {
        cout << endl << "Clien: Unbekannter Fehler!";
    }

    return 1;
}

using namespace std;
int main(int argc, char** argv)
{
    // clinet_1(argc, argv);
    return client_3(argc, argv);
   
}