#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class dofile {
    fstream file;
    string filename;

public:
    class FileException {
        string msg;
    public:
        FileException(const string& m) : msg(m) {}
        string what() const { return msg; }
    };

    dofile(const string& fname, ios::openmode mode = ios::in | ios::out) : filename(fname) {
        file.open(filename, mode);
        if (!file.is_open())
            throw FileException("Cannot open file: " + filename);
    }

    void reset() {
        file.clear();
        file.seekg(0, ios::beg);
        file.seekp(0, ios::beg);
        if (!file.good())
            throw FileException("Cannot reset file pointer for: " + filename);
    }

    void writeLine(const string& line) {
        if (!(file << line << endl))
            throw FileException("Write failed for: " + filename);
    }

    string readLine() {
        string line;
        if (!getline(file, line))
            throw FileException("Read failed or end of file: " + filename);
        return line;
    }

    ~dofile() {
        if (file.is_open())
            file.close();
    }
};

int main() {
    try {
        dofile df("testfile.txt", ios::in | ios::out | ios::trunc);

        df.writeLine("Hello, world!");
        df.writeLine("This is a test file.");

        df.reset();

        while (true) {
            cout << df.readLine() << endl;
        }

    } catch (dofile::FileException &e) {
        cout << "File error: " << e.what() << endl;
    }

    return 0;
}
