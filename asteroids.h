#ifndef LECTURER_H
#define LECTURER_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::ifstream, std::left, std::ostream, std::right, std::setw, std::string, std::vector;

class asteroids {
private:
    string id, full_name, name, neo, potHazd;
    int skpid;
    double abs_mgnt, diam;
public:
    // Creating general constructor
    asteroids() {
        this->id = "Unknown";
        this->skpid = 0;
        this->full_name = "Unknown";
        this->name = "Unknown";
        this->neo = "N";
        this->potHazd = "N";
        this->abs_mgnt = 0;
        this->diam = 0;
    }
    // Creating constructor
    asteroids(string id, int skpid, string full_name, string name, string neo, string potHazd, double abs_mgnt, double diam) {
        this->id = id;
        this->skpid = skpid;
        this->full_name = full_name;
        this->name = name;
        this->neo = neo;
        this->potHazd = potHazd;
        this->abs_mgnt = abs_mgnt;
        this->diam = diam;
    }


    // Make the getters
    string get_id() {
        return this->id;
    }
    int get_skpid() {
        return this->skpid;
    }
    string get_full_name() {
        return this->full_name;
    }
    string get_name() {
        return this->name;
    }
    string get_neo() {
        return this->neo;
    }
    string get_potHzd() {
        return this->potHazd;
    }
    double get_mgnt() {
        return this->abs_mgnt;
    }
    double get_diam() {
        return this->diam;
    }


    // Make the setters
    void setId(string id) {
        this->id = id;
    }
    void setSkpid(int skpid) {
        this->skpid = skpid;
    }
    void setFullName(string full_name) {
        this->full_name = full_name;
    }
    void setName(string name) {
        this->name = name;
    }
    void setNeo(string neo) {
        this->neo = neo;
    }
    void set_potHazd(string potHazd) {
        this->potHazd = potHazd;
    }
    void set_mgnt(double mgnt) {
        this->abs_mgnt = mgnt;
    }
    void set_diam(double diam) {
        this->diam = diam;
    }

    // Override the "<<" operator so that it formats the output stream
    friend ostream& operator << (ostream& outs, const asteroids& ast) {
        outs  <<  "ID: " << left << setw(15) << ast.id;
        outs <<  "SKPID: " << setw(15) << ast.skpid;
        outs << "Full Name: " << setw(30) << ast.full_name;
        outs <<  "Name: " << setw(12) << ast.name;
        outs << "Near Earth Object: " << setw(5) << ast.neo;
        outs << "Potential Hazard:" << setw(8) << ast.potHazd;
        outs << "Magnitude: " << setw(9) << ast.abs_mgnt;
        outs << "Diameter: " << setw(8) << ast.diam;
        return outs;
    }

    // Overrides the "==" so that it can compare two Asteroid Objects
    friend bool operator == (const asteroids& lhs, const asteroids& rhs) {
        return lhs.id == rhs.id;
    }

    friend bool operator < (const asteroids& lhs, const asteroids& rhs) {
        return lhs.id < rhs.id;
    }

    friend bool operator > (const asteroids& lhs, const asteroids& rhs) {
        return lhs.id > rhs.id;
    }

    friend bool operator <= (const asteroids& lhs, const asteroids& rhs) {
        return lhs.id <= rhs.id;
    }

    friend bool operator >= (const asteroids& lhs, const asteroids& rhs) {
        return lhs.id >= rhs.id;
    }

    friend bool operator != (const asteroids& lhs, const asteroids& rhs) {
        return lhs.id != rhs.id;
    }
};

// Retrieves the average magnitude of all asteroids in the vector
double avgMgnt(vector<asteroids>& ast) {
    double total = 0;
    // Sums all magnitudes in the vector
    for (int i = 0; i < ast.size(); ++i) {
        total += ast[i].get_mgnt();
    }
    // Returns the mean value of the magnitudes
    return (total / ast.size());
}

// Retrieves the length of the shortest name in the vector (Io, line 85)
double shortestName(vector<asteroids>& ast) {
    // Shortest length set to large number relative to max length
    int shortest_length = 100;
    // Filters through all names in the vector and decide the shortest
    for (int i = 0; i < ast.size(); i++) {
       if (ast[i].get_name().length() < shortest_length) {
           shortest_length = ast[i].get_name().length();
       }
    }
    // Return the shortest length name
    return shortest_length;
}

// Get data from file retrieves all data from asteroids vector and formats the output stream
bool getDataFromFile(vector<asteroids>& asteroid){
    ifstream fileIn;
    fileIn.open("../ASTEROIDS_FILE(Sheet1).csv");

    if (fileIn) {
        cout<<"File opened"<<endl;

        string header;
        getline(fileIn,header);
        cout<<header<<endl;

        string id = "a0000000", full_name= "Unknown", name = "Unknown", neo = "N", potHazd = "N", newline = "";
        int skpid = 0;
        double abs_mgnt = 0.0, diam = 0.0;
        char comma;

        // Reads in all data on a single line from Book(Sheet1).csv
        while(fileIn) {
            getline(fileIn,id,',');

            fileIn >> skpid;
            if (!fileIn) {
                skpid = 0;
                fileIn.clear();
            }
            fileIn >> comma;
            //getline(fileIn,skpid,',');
            getline(fileIn,full_name,',');
            getline(fileIn,name,',');
            getline(fileIn,neo,',');
            getline(fileIn,potHazd,',');

            fileIn >> abs_mgnt;
            if (!fileIn) {
                abs_mgnt = 0.0;
                fileIn.clear();
            }
            fileIn >> comma;

            fileIn >> diam;
            if (!fileIn) {
                diam = 0.0;
                fileIn.clear();
            }
            // Gets rid of the new line character
            getline(fileIn, newline);
            //Store the data from the row into a Lecturer object, in a vector.
            asteroid.push_back(asteroids(id, skpid, full_name, name, neo, potHazd, abs_mgnt, diam));
        }
        // Close the file when done using
        fileIn.close();
    }
    // If file can not be found, return false
    else {
        cout<<"Error opening file"<<endl;
        return false;
    }
    // Return true otherwise
    return true;
}


#endif //STARS_H
