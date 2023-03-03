#include <iostream>
using namespace std;

void provokeError() {

    bool error_string = true;
    bool error_char = true;
    // Equivalent to const char *
    char char_error[] = "A char error was caught";
    string string_error = "A string error was caught";

    if (error_string) {
        throw string("A string error was caught");
    }
    if (error_char) {
        throw "A char error was caught";
    }

    cout << "Error did not occur" << endl;
}



int main() {
    try {
        provokeError();
    }
    catch (const int e){
        cout << "Caught error: " << e << endl;
    }
    // Catch as reference to avoid errors due to inheritance and creating a new object
    catch (string &e) {
        cout << "Caught other error: " << e << endl;
    }
    return 0;
}