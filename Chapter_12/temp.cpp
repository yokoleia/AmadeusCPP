#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    string yourUsername;
    string yourDomain;

    cin >> yourUsername;
    cin >> yourDomain;

    try
    {
        if ((yourUsername.size() < 4) || (yourUsername.size()>10)) {
            throw runtime_error("User name's length must be between 4 and 10");
        } else if ((yourDomain.at(0) != '@')) {
            throw runtime_error("Domain must start with '@'");
        } else {
            cout << "Sending email to " << yourUsername << yourDomain << endl;//Santino@carrot"
        }

    }
    catch (runtime_error &excpt)
    {
        cout << "Error: " << excpt.what() << endl;
    }

    return 0;
}