#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <iomanip>

using namespace std;

//------------------------------------------------CLASSES-------------------------------------------//

/////////////////////////////// Details Portion (NASHRA GHAFFAR) CT-032 /////////////////////////////


// *****1.Doctors Details Class*****//

class Doctors_Details
{
private:
    string D_salary;

protected:
    string D_id, D_name, D_shiftTimings, D_address, D_gender, D_specialization, D_contactNumber, D_cnicNumber, D_age;

public:
    string remID;
    void commonInputs();
    void getDocDetails();
    void showDocDetails();
    void removeDocDetail();
    Doctors_Details() // Constructor
    {

        D_id = "";
        D_salary = "";
        D_age = "";
        D_name = "";
        D_shiftTimings = "";
        D_address = "";
        D_gender = "";
        D_specialization = "";
        D_contactNumber = "";
        D_cnicNumber = "";
    }
};

//Functions of Doctors Details Class

// 1. Add Doctor()
// 2. Show Doctor Details()
// 3. Delete Doctor Detail()

// 1
void Doctors_Details::commonInputs()
{
    cout << "ID  (101,102,etc..) : " << endl;
    cout << "Name : " << endl;
    cout << "Address : " << endl;
    cout << "Gender : " << endl;
    cout << "CNIC Number : " << endl;
    cout << "Contact Number : " << endl;
    cout << "Age : " << endl;
}
void Doctors_Details ::getDocDetails()
{
    ofstream writingDocDetail("DoctorDetail.txt", ios::app);
    system("cls");
    cin.ignore();
    Doctors_Details::commonInputs();
    cout << "Specialization : " << endl;
    cout << "Shift Timings (e.g : 9AM - 9PM) : " << endl;
    cout << "Salary : " << endl;

    // Id
    COORD a;
    a.X = 50;
    a.Y = 0;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), a);
    getline(cin, D_id);

    writingDocDetail << "\n"
                     << D_id << "\n";
    int idLen = D_id.length();
    for (int i = 0; i < idLen; i++)
    { //Generating a design
        writingDocDetail << "=";
    }

    //Name
    COORD b;
    b.X = 50;
    b.Y = 1;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), b);
    getline(cin, D_name);
    int nameLen = D_name.length();
    for (int i = 0; i < nameLen; i++)
    {
        if (i == 0) //Conerting character at first index to uppercase.
        {
            D_name[i] = toupper(D_name[i]);
        }
        else if (D_name[i] == ' ')
        {
            D_name[i + 1] = toupper(D_name[i + 1]);
        }
    }
    writingDocDetail << "\t\nName: " + D_name;

    //ADDRESS
    COORD c;
    c.X = 50;
    c.Y = 2;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
    getline(cin, D_address);
    writingDocDetail << "\nADDRESS: " + D_address;

    //Gender
    COORD f;
    f.X = 50;
    f.Y = 3;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), f);
    getline(cin, D_gender);
    writingDocDetail << "\nGENDER: " + D_gender;
    //Cnic
    COORD g;
    g.X = 50;
    g.Y = 4;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), g);
    getline(cin, D_cnicNumber);
    writingDocDetail << "\nCNIC NUMBER: " << D_cnicNumber;
    //Contact
    COORD h;
    h.X = 50;
    h.Y = 5;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), h);
    getline(cin, D_contactNumber);
    writingDocDetail << "\nCONTACT NUMBER: " << D_contactNumber;
    //Age
    COORD j;
    j.X = 50;
    j.Y = 6;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), j);
    getline(cin, D_age);
    writingDocDetail << "\nAGE:" + D_age;

    //Specialisation
    COORD d;
    d.X = 50;
    d.Y = 7;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), d);
    getline(cin, D_specialization);
    writingDocDetail << "\nSPECIALISATION: " + D_specialization;
    //Shift timings
    COORD e;
    e.X = 50;
    e.Y = 8;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), e);
    getline(cin, D_shiftTimings);
    writingDocDetail << "\nSHIFT TIMINGS: " + D_shiftTimings;
    //Salary
    COORD i;
    i.X = 50;
    i.Y = 9;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), i);
    getline(cin, D_salary);
    writingDocDetail << "\nSALARY: " << D_salary;

    writingDocDetail << "\n";

    cin.ignore();
    writingDocDetail.close();
}

// 2.
void Doctors_Details ::showDocDetails()
{
    cout << "DOCTORS DETAILS" << endl;
    string allDetails;
    ifstream readingFiles("DoctorDetail.txt");
    while (!readingFiles.eof())
    { // keep reading until end-of-file
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
    readingFiles.close();
}

// 3.
void Doctors_Details ::removeDocDetail()
{

    string line, id;
    int found = 0;
    ifstream readDocDet("DoctorDetail.txt");
    ofstream writeNewDocDet("tempDoctor.txt");
    cout << "\n\n\t\t\tEnter id of the Doctor you want to delete: ";
    cin.ignore();
    getline(cin, id);
    int skip = 0;
    while (getline(readDocDet, line))
    {
        if (id == line)
        {
            found = 1;
        }
        if ((line != id) && !(skip > 0))
        {
            writeNewDocDet << line << endl;
        }
        else
        {
            if (skip == 0)
            {
                skip = 10;
            }
            else
            {
                --skip;
            }
        }
    }

    if (found == 0)
    {
        cout << "\n\t\t\t Sorry !! No ID found .." << endl;
    }
    else
    {
        cout << "\n\n\t\t\t ***    Detail Deleted Successfully    ***" << endl;
    }
    readDocDet.close();
    writeNewDocDet.close();
    remove("DoctorDetail.txt");
    rename("tempDoctor.txt", "DoctorDetail.txt");
}

// *****2.Patients Details Class*****//

//INHERITAANCCE

class Patient_Details : public Doctors_Details
{
protected:
    string P_id, P_name, P_address, P_gender, P_contactNumber,
        P_cnicNumber, P_age, P_disease, P_room_no;

public:
    void getPatDetails();
    void removePatDetail();
    void showPatDetails();
    Patient_Details() // Constructor
    {
        P_room_no = "";
        P_id = "";
        P_age = "";
        P_name = "";
        P_address = "";
        P_gender = "";
        P_contactNumber = "";
        P_cnicNumber = "";
        P_disease = "";
    }
};

//Functions of Patient Details Class

// 1. Add Patient
// 2. Show Patient
// 3. remove Patient

// 1
void Patient_Details ::getPatDetails()
{
    ofstream writingPatDetail("PatientDetail.txt", ios::app);
    system("cls");
    cin.ignore();
    cout << "Room Number(1-15) : " << endl;
    //INHERITANCE
    Doctors_Details::commonInputs();
    cout << "Disease : " << endl;
    //Room no
    COORD a;
    a.X = 50;
    a.Y = 0;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), a);

    getline(cin, P_room_no);
    writingPatDetail << "\n\n" + P_room_no + "\n";
    int nameLen = P_room_no.length();
    for (int i = 0; i < nameLen; i++)
    { //Generating a design
        writingPatDetail << "=";
    }

    //    ID
    COORD b;
    b.X = 50;
    b.Y = 1;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), b);
    getline(cin, P_id);
    writingPatDetail << "\nID: " + P_id;

    //Name
    COORD c;
    c.X = 50;
    c.Y = 2;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
    getline(cin, P_name);

    for (int i = 0; i < nameLen; i++)
    {
        if (i == 0) //Conerting character at first index to uppercase.
        {
            P_name[i] = toupper(P_name[i]);
        }
        else if (P_name[i] == ' ')
        {
            P_name[i + 1] = toupper(P_name[i + 1]);
        }
    }
    writingPatDetail << "\nName: " + P_name;

    // Address
    COORD d;
    d.X = 50;
    d.Y = 3;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), d);
    // cout << "Address : " << endl;
    getline(cin, P_address);
    writingPatDetail << "\nADDRESS: " + P_address;

    //Gendwr
    COORD e;
    e.X = 50;
    e.Y = 4;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), e);
    // cout << "Gender : " << endl;
    getline(cin, P_gender);
    writingPatDetail << "\nGENDER: " + P_gender;

    //CNIC
    COORD f;
    f.X = 50;
    f.Y = 5;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), f);
    // cout << "CNIC Number : " << endl;
    getline(cin, P_cnicNumber);
    writingPatDetail << "\nCNIC NUMBER: " << P_cnicNumber;

    //Contact
    COORD g;
    g.X = 50;
    g.Y = 6;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), g);
    getline(cin, P_contactNumber);
    writingPatDetail << "\nCONTACT NUMBER: " << P_contactNumber;
    //Age

    COORD h;
    h.X = 50;
    h.Y = 7;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), h);
    // cout << "Age : " << endl;
    getline(cin, P_age);
    writingPatDetail << "\nAGE: " + P_age;

    //Disease
    COORD i;
    i.X = 50;
    i.Y = 8;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), i);
    getline(cin, P_disease);
    writingPatDetail << "\nDISEASE: " + P_disease;
    writingPatDetail << "\n";

    cin.ignore();
    writingPatDetail.close();
}

// 2.
void Patient_Details ::showPatDetails()
{
    system("cls");

    cout << "PATIENT DETAILS" << endl;
    string allDetails;
    ifstream readingFiles("PatientDetail.txt");
    while (!readingFiles.eof())
    { // keep reading until end-of-file
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
    readingFiles.close();
}

// 3.
void Patient_Details ::removePatDetail()
{

    string line, roomNo;
    int found = 0;
    ifstream readPatDet("PatientDetail.txt");
    ofstream writeNewPatDet("tempPatient.txt");
    cin.ignore();
    cout << "\n\n\t\t\tEnter the room no of Patient you want to delete(1-15):  ";
    getline(cin, roomNo);
    int skip = 0;
    while (getline(readPatDet, line))
    {
        if (roomNo == line)
        {
            found = 1;
        }
        if ((line != roomNo) && !(skip > 0))
        {
            writeNewPatDet << line << endl;
        }
        else
        {
            if (skip == 0)
            {
                skip = 10;
            }
            else
            {
                --skip;
            }
        }
    }
    if (found == 0)
    {
        cout << "\n\t\t\t Sorry !! No Room no. found .." << endl;
    }
    else
    {
        cout << "\n\n\t\t\t ***    Detail Deleted Successfully    ***" << endl;
    }
    readPatDet.close();
    writeNewPatDet.close();
    remove("PatientDetail.txt");
    rename("tempPatient.txt", "PatientDetail.txt");
}

// *****3.Side Workers Details Class*****//

class SideWorker_Details
{
protected:
    string SW_id, SW_name, SW_contactNumber, SW_salary;

public:
    void getSWDetails();
    void showSWDetails();
    void removeSWDetail();

    SideWorker_Details() // Constructor
    {
        SW_id = "";
        SW_name = "";
        SW_contactNumber = "";
        SW_salary = "";
    }
};
//Functions of Sideworker Details Class

// 1. Add Sideworker
// 2. Show Sideworker
// 3. Delete Sideworker

// 1

void SideWorker_Details ::getSWDetails()
{
    ofstream writingSWDetail("SideWorkerDetail.txt", ios::app);
    system("cls");
    cin.ignore();

    cout << "Enter Sideworker's ID  (101,102,etc..) : " << endl;
    getline(cin, SW_id);
    writingSWDetail << "\n"
                    << SW_id << "\n";

    int idLen = SW_id.length();
    for (int i = 0; i < idLen; i++)
    { //Generating a design
        writingSWDetail << "=";
    }

    cout << "Name : " << endl;
    getline(cin, SW_name);
    int nameLen = SW_name.length();
    for (int i = 0; i < nameLen; i++)
    {
        if (i == 0) //Conerting character at first index to uppercase.
        {
            SW_name[i] = toupper(SW_name[i]);
        }
        else if (SW_name[i] == ' ')
        {
            SW_name[i + 1] = toupper(SW_name[i + 1]);
        }
    }
    writingSWDetail << "\t\nName: " + SW_name;

    cout << "Salary : " << endl;
    getline(cin, SW_salary);
    writingSWDetail << "\nSALARY: " + SW_salary;

    cout << "Contact Number : " << endl;
    getline(cin, SW_contactNumber);
    writingSWDetail << "\nCONTACT NUMBER: " << SW_contactNumber;

    cin.ignore();
    writingSWDetail.close();
}
// 2.
void SideWorker_Details ::showSWDetails()
{
    cout << "SideWorker DETAILS" << endl;
    string allDetails;
    ifstream readingFiles("SideWorkerDetail.txt");
    while (!readingFiles.eof())
    {
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
    readingFiles.close();
}

// 3.
void SideWorker_Details ::removeSWDetail()
{

    string line, id;
    int found = 0;
    ifstream readSWDet("SideWorkerDetail.txt");
    ofstream writeNewSWDet("tempSideWorker.txt");
    cin.ignore();
    cout << "\n\n\t\t\tEnter id of the SideWorker you want to delete: ";
    getline(cin, id);
    int skip = 0;
    while (getline(readSWDet, line))
    {
        if (id == line)
        {
            found = 1;
        }
        if ((line != id) && !(skip > 0))
        {
            writeNewSWDet << line << endl;
        }
        else
        {
            if (skip == 0)
            {
                skip = 5;
            }
            else
            {
                --skip;
            }
        }
    }
    if (found == 0)
    {
        cout << "\n\t\t\t Sorry !! No ID found .." << endl;
    }
    else
    {
        cout << "\n\n\t\t\t ***    Detail Deleted Successfully    ***" << endl;
    }
    readSWDet.close();
    writeNewSWDet.close();
    remove("SideWorkerDetail.txt");
    rename("tempSideWorker.txt", "SideWorkerDetail.txt");
}

// =================================  Nashra's Details Portion End ================================= //




/////////////////////////////// Management Portion (Muhammad Abdul Rafay) CT-12 /////////////////////////////

// *****1.Room Management Class*****//

class Room_management : public Patient_Details
{
private:
    int R_room, R_found;
    string R_line, R_roomStr;

public:
    //Constructor
    Room_management()
    {
        R_room = 0;
        R_found = 0;
        R_line = "";
        R_roomStr = "";
    }
    void showRoomDetails();
    void admitPatient();
    void dischargePatient();
};

//1.
void Room_management::showRoomDetails()
{
    cout << "\t\t\t\t--------------------------------------------------" << endl;
    cout << "\t\t\t\t            ROOMS               STATUS" << endl;
    cout << "\t\t\t\t--------------------------------------------------" << endl;
    ofstream writeRoomFile("RoomDetails.txt");
    for (int i = 0; i <= 8; i++)
    {
        ifstream readPatientFile("PatientDetail.txt");
        R_room = R_room + 1; //value 1
        while (!readPatientFile.eof())
        {
            getline(readPatientFile, R_line);
            //room1
            stringstream ss;
            ss << R_room;

            ss >> R_roomStr;

            if (R_line == R_roomStr)
            {
                R_found = 1;
            }
        }

        if (R_found == 1)
        {
            writeRoomFile << "             00" << R_room << "               "
                          << "Reserved" << endl;
            R_found = 0;
        }
        else
        {
            writeRoomFile << "             00" << R_room << "               "
                          << "Available" << endl;
        }
        readPatientFile.close();
    }
    writeRoomFile.close();

    string allDetails;
    ifstream readingFiles("RoomDetails.txt");
    while (!readingFiles.eof())
    { // keep reading until end-of-file
        getline(readingFiles, allDetails);
        cout << "\t\t\t\t" << allDetails << endl;
    }
    readingFiles.close();
    R_room=0;
}

//2. (Inheritance)
void Room_management ::admitPatient()
{
    getPatDetails();
}
void Room_management :: dischargePatient(){
    removePatDetail();
}
// *****2.Ambulance Management Class*****//

class Ambulance_management
{
private:
    string AD_salary;

protected:
    string A_veh_type, A_type, A_num, A_count, AD_name, AD_cnic, A_all_details, AD_age, AD_ID;

public:
    //Constructor
    Ambulance_management()
    {
        A_veh_type = "";
        A_type = "";
        A_num = "";
        A_count = "";
        AD_name = "";
        AD_cnic = "";
        A_all_details = "";
        AD_age = "";
        AD_ID = "";
    }
    void register_ambulance();
    void add_driver();
    void show_ambulance();
    void show_driver();
};
//1.
void Ambulance_management ::register_ambulance()
{

    ofstream WritingAmbulace("AmbulanceDetail.txt", ios::app);

    // system("cls");
    cin.ignore();

    cout << "\n\n\t\t Enter the type of your Ambulance (Emergency or Patient Transport ?) ";
    getline(cin, A_type);
    WritingAmbulace << "\nAmbulance type: " + A_type;

    cout << "\n\t\t Which vehicle are you going to convert into ambulance (car,hiroof,etc..): ";
    getline(cin, A_veh_type);
    WritingAmbulace << "\nAmbulance Vehichle Type: " + A_veh_type;

    cout << "\n\t\tEnter the number of your vehicle: ";
    getline(cin, A_num);
    WritingAmbulace << "\nAmbulance number: " + A_num + "\n";
    WritingAmbulace << "--------------------------------------------";
    cin.ignore();
    // cout<<"\n\n\t\t\tPress Enter Key to continue...."<<endl;
};
//2.
void Ambulance_management ::show_ambulance()
{
    ifstream ReadAmbulance("AmbulanceDetail.txt");
    while (!ReadAmbulance.eof())
    { // keep reading until end-of-file
        getline(ReadAmbulance, A_all_details);
        cout << A_all_details << endl;
    }
};
//3.
void Ambulance_management ::add_driver()
{

    system("cls");
    cin.ignore();
    ofstream WritingDriver("DriverDetail.txt", ios::app);
    cout << "Driver ID: ";
    getline(cin, AD_ID);
    WritingDriver << "\n\nID: " + AD_ID;
    WritingDriver << "\n========";

    cout << "Driver Name: ";
    getline(cin, AD_name);
    WritingDriver << "\nName: " + AD_name;

    cout << "Driver CNIC: ";
    getline(cin, AD_cnic);
    WritingDriver << "\nCNIC: " + AD_cnic;

    cout << "Driver Age: ";
    getline(cin, AD_age);
    WritingDriver << "\nAge: " + AD_age;

    cout << "Driver Salary: ";
    getline(cin, AD_salary);
    WritingDriver << "\nSalary: " + AD_salary;
};
//4.
void Ambulance_management ::show_driver()
{
    ifstream ReadDriver("DriverDetail.txt");
    string AD_all_details;
    while (!ReadDriver.eof())
    { // keep reading until end-of-file
        getline(ReadDriver, AD_all_details);
        cout << AD_all_details << endl;
    }
};

// *****3.Staff Management Class*****//

// (Inheritance)

class Staff_Management : public Doctors_Details, public SideWorker_Details
{   Doctors_Details D_obj;
    SideWorker_Details S_obj;
    
public:
    void showAllStaff();
    void deleteAllStaff();
};

void Staff_Management ::showAllStaff()
{
    showDocDetails();
    showSWDetails();
}

void Staff_Management ::deleteAllStaff()
{

    std::ofstream ofs;
    ofs.open("DoctorDetail.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    std::ofstream ofw;
    ofw.open("SideWorkerDetail.txt", std::ofstream::out | std::ofstream::trunc);
    ofw.close();
    cout << "\n\t\t\t All the staff Record has been deleted..";
}

/////////////////////////////// Pharmacy Portion (MINAHIL TARIQ) CT-26 /////////////////////////////

// *****1.Medicine Class*****//

//Functions of Medicine Class

// 1. Availability of Medicines
// 2. Buy Medicine

class Medicine
{
private:
    string M_medname, M_dosage, M_medicine_buyer;

public:
    void Availability_of_Medicines();
    void Buy_Medicine();
    Medicine() // Constructor
    {
        M_medname = "";
        M_dosage = "";
        M_medicine_buyer = "";
    }
};

void Medicine ::Availability_of_Medicines()
{
    system("cls");
    string allDetails;
    ifstream readingFiles("Medicines_Details.txt");
    while (!readingFiles.eof())
    { // keep reading until end-of-file
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
}

void Medicine ::Buy_Medicine()
{
    ofstream BuyingMedicine("Medicines_Sold.txt", ios::app);
    system("cls");
    cin.ignore();

    cout << "\n\n***********MEDCINES AVAILABLE IN PHARMACY************: " << endl;
    cout << "\n\n1)  Medicine Name: PANADOL" << endl;
    cout << "    Dosages Available: 250mg, 500mg" << endl;
    cout << "    Price: Rs300, Rs420 " << endl;
    cout << "\n2)  Medicine Name: NOVEX" << endl;
    cout << "    Dosages Available: 9mg" << endl;
    cout << "    Price: Rs550 " << endl;
    cout << "\n3)  Medicine Name: WYMOX" << endl;
    cout << "    Dosages Available: 25mg, 45mg" << endl;
    cout << "    Price: Rs200, Rs340 " << endl;
    cout << "\n4)  Medicine Name: AUGMENTIN" << endl;
    cout << "    Dosages Available: 250mg, 500mg" << endl;
    cout << "    Price: Rs300, Rs550 " << endl;
    cout << "\n5)  Medicine Name: CALAMOX" << endl;
    cout << "    Dosages Available: 25mg, 50mg, 375mg, 6225mg" << endl;
    cout << "    Price: Rs200, Rs300, Rs440, Rs500 " << endl;
    cout << "\n6)  Medicine Name: VOLSEF" << endl;
    cout << "    Dosages Available: 500mg" << endl;
    cout << "    Price: Rs360 " << endl;
    cout << "\n7)  Medicine Name: CEFSPAN" << endl;
    cout << "    Dosages Available: 200mg" << endl;
    cout << "    Price: Rs400 " << endl;
    cout << "\n8)  Medicine Name: TRAMADOL" << endl;
    cout << "    Dosages Available: 500mg" << endl;
    cout << "    Price: Rs850 " << endl;
    cout << "\n9)  Medicine Name: PONSTAN" << endl;
    cout << "    Dosages Available: 500mg" << endl;
    cout << "    Price: Rs500 " << endl;
    cout << "\n10) Medicine Name: ZURIG" << endl;
    cout << "    Dosages Available: 40mg 10'S, 80mg, 40mg 20'S" << endl;
    cout << "    Price: Rs450, Rs550, Rs600 " << endl;
    cout << "\n\nSelect Medicine (1-10) from above list: ";
    getline(cin, M_medname);
    if (M_medname == "1")
    {
        cout << "\nEnter Dosage (e.g 100mg, 200mg etc): ";
        getline(cin, M_dosage);
        if (M_dosage == "250mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "PANADOL" << endl;
            BuyingMedicine << "250mg" << endl;
            BuyingMedicine << "Your bill is Rs300 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout << "\n\n************************"<<endl;        
            cout<<"PANADOL"<<endl;
            cout<<"250mg"<<endl;
            cout<<"Your bill is Rs300 /-"<<endl;
            cout<<"************************"<<endl;
        }
        else if (M_dosage == "500mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "PANADOL" << endl;
            BuyingMedicine << "500mg" << endl;
            BuyingMedicine << "Your bill is Rs420 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"PANADOL"<<endl;
            cout<<"500mg"<<endl;
            cout<<"Your bill is Rs420 /-"<<endl;
            cout<<"************************"<<endl;
        }
    }
    else if (M_medname == "2")
    {
        cout << "Your Name: " << endl;
        getline(cin, M_medicine_buyer);
        int nameLen = M_medicine_buyer.length();

        for (int i = 0; i < nameLen; i++)
        {
            if (i == 0) //Conerting character at first index to uppercase.
            {
                M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
            }
            else if (M_medicine_buyer[i] == ' ')
            {
                M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
            }
        }
        BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
        BuyingMedicine << "\n\n************************" << endl;
        BuyingMedicine << "NOVEX" << endl;
        BuyingMedicine << "9mg" << endl;
        BuyingMedicine << "Your bill is Rs550 /-" << endl;
        BuyingMedicine << "************************" << endl;
        cout << "\t\n\nBUYER: " + M_medicine_buyer;
        cout<<"\n\n************************"<<endl;
        cout<<"NOVEX"<<endl;
        cout<<"9mg"<<endl;
        cout<<"Your bill is Rs550 /-"<<endl;
        cout<<"************************"<<endl;
    }
    else if (M_medname == "3")
    {
        cout << "\nEnter Dosage (e.g 100mg, 200mg etc): ";
        getline(cin, M_dosage);
        if (M_dosage == "25mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "WYMOX" << endl;
            BuyingMedicine << "25mg" << endl;
            BuyingMedicine << "Your bill is Rs200 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"WYMOX"<<endl;
            cout<<"25mg"<<endl;
            cout<<"Your bill is Rs200 /-"<<endl;
            cout<<"************************"<<endl;
        }
        else if (M_dosage == "50mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "WYMOX" << endl;
            BuyingMedicine << "50mg" << endl;
            BuyingMedicine << "Your bill is Rs340 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"WYMOX"<<endl;
            cout<<"50mg"<<endl;
            cout<<"Your bill is Rs340 /-"<<endl;
            cout<<"************************"<<endl;
        }
    }
    else if (M_medname == "4")
    {
        cout << "\nEnter Dosage (e.g 100mg, 200mg etc): ";
        getline(cin, M_dosage);
        if (M_dosage == "25mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "AUGMENTIN" << endl;
            BuyingMedicine << "25mg" << endl;
            BuyingMedicine << "Your bill is Rs300 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"AUGMENTIN"<<endl;
            cout<<"25mg"<<endl;
            cout<<"Your bill is Rs300 /-"<<endl;
            cout<<"************************"<<endl;
        }
        else if (M_dosage == "500mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "AUGMENTIN" << endl;
            BuyingMedicine << "500mg" << endl;
            BuyingMedicine << "Your bill is Rs550 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"AUGMENTIN"<<endl;
            cout<<"500mg"<<endl;
            cout<<"Your bill is Rs550 /-"<<endl;
            cout<<"************************"<<endl;
        }
    }
    else if (M_medname == "5")
    {
        cout << "\nEnter Dosage (e.g 100mg, 200mg etc): ";
        getline(cin, M_dosage);
        if (M_dosage == "25mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "CALAMOX" << endl;
            BuyingMedicine << "25mg" << endl;
            BuyingMedicine << "Your bill is Rs200 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"CALAMOX"<<endl;
            cout<<"25mg"<<endl;
            cout<<"Your bill is Rs200 /-"<<endl;
            cout<<"************************"<<endl;
        }
        else if (M_dosage == "50mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "CALAMOX" << endl;
            BuyingMedicine << "50mg" << endl;
            BuyingMedicine << "Your bill is Rs300 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"CALAMOX"<<endl;
            cout<<"50mg"<<endl;
            cout<<"Your bill is Rs300 /-"<<endl;
            cout<<"************************"<<endl;
        }
        else if (M_dosage == "37Smg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "CALAMOX" << endl;
            BuyingMedicine << "375mg" << endl;
            BuyingMedicine << "Your bill is Rs440 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"CALAMOX"<<endl;
            cout<<"375mg"<<endl;
            cout<<"Your bill is Rs440 /-"<<endl;
            cout<<"************************"<<endl;
        }
        else if (M_dosage == "6225mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "CALAMOX" << endl;
            BuyingMedicine << "6225mg" << endl;
            BuyingMedicine << "Your bill is Rs500 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"CALAMOX"<<endl;
            cout<<"6225mg"<<endl;
            cout<<"Your bill is Rs500 /-"<<endl;
            cout<<"************************"<<endl;
        }
    }
    else if (M_medname == "6")
    {
        cout << "Your Name: " << endl;
        getline(cin, M_medicine_buyer);
        int nameLen = M_medicine_buyer.length();

        for (int i = 0; i < nameLen; i++)
        {
            if (i == 0) //Conerting character at first index to uppercase.
            {
                M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
            }
            else if (M_medicine_buyer[i] == ' ')
            {
                M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
            }
        }
        BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
        BuyingMedicine << "\n\n************************" << endl;
        BuyingMedicine << "VOLSEF" << endl;
        BuyingMedicine << "500mg" << endl;
        BuyingMedicine << "Your bill is Rs360 /-" << endl;
        BuyingMedicine << "************************" << endl;
        cout << "\t\n\nBUYER: " + M_medicine_buyer;
        cout<<"\n\n************************"<<endl;
        cout<<"VOLSEF"<<endl;
        cout<<"500mg"<<endl;
        cout<<"Your bill is Rs360 /-"<<endl;
        cout<<"************************"<<endl;
    }
    else if (M_medname == "7")
    {
        cout << "Your Name: " << endl;
        getline(cin, M_medicine_buyer);
        int nameLen = M_medicine_buyer.length();

        for (int i = 0; i < nameLen; i++)
        {
            if (i == 0) //Conerting character at first index to uppercase.
            {
                M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
            }
            else if (M_medicine_buyer[i] == ' ')
            {
                M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
            }
        }
        BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
        BuyingMedicine << "\n\n************************" << endl;
        BuyingMedicine << "CEFSPAN" << endl;
        BuyingMedicine << "200mg" << endl;
        BuyingMedicine << "Your bill is Rs400 /-" << endl;
        BuyingMedicine << "************************" << endl;
        cout << "\t\n\nBUYER: " + M_medicine_buyer;
        cout<<"\n\n************************"<<endl;
        cout<<"CEFSPAN"<<endl;
        cout<<"200mg"<<endl;
        cout<<"Your bill is Rs400 /-"<<endl;
        cout<<"************************"<<endl;
    }
    else if (M_medname == "8")
    {
        cout << "Your Name: " << endl;
        getline(cin, M_medicine_buyer);
        int nameLen = M_medicine_buyer.length();

        for (int i = 0; i < nameLen; i++)
        {
            if (i == 0) //Conerting character at first index to uppercase.
            {
                M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
            }
            else if (M_medicine_buyer[i] == ' ')
            {
                M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
            }
        }
        BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
        BuyingMedicine << "\n\n************************" << endl;
        BuyingMedicine << "TRAMADOL" << endl;
        BuyingMedicine << "500mg" << endl;
        BuyingMedicine << "Your bill is Rs850 /-" << endl;
        BuyingMedicine << "************************" << endl;
        cout << "\t\n\nBUYER: " + M_medicine_buyer;
        cout<<"\n\n************************"<<endl;
        cout<<"TRAMADOL"<<endl;
        cout<<"500mg"<<endl;
        cout<<"Your bill is Rs850 /-"<<endl;
        cout<<"************************"<<endl;
    }
    else if (M_medname == "9")
    {
        cout << "Your Name: " << endl;
        getline(cin, M_medicine_buyer);
        int nameLen = M_medicine_buyer.length();

        for (int i = 0; i < nameLen; i++)
        {
            if (i == 0) //Conerting character at first index to uppercase.
            {
                M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
            }
            else if (M_medicine_buyer[i] == ' ')
            {
                M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
            }
        }
        BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
        BuyingMedicine << "\n\n************************" << endl;
        BuyingMedicine << "PONSTAN" << endl;
        BuyingMedicine << "500mg" << endl;
        BuyingMedicine << "Your bill is Rs500 /-" << endl;
        BuyingMedicine << "************************" << endl;
        cout << "\t\n\nBUYER: " + M_medicine_buyer;
        cout<<"\n\n************************"<<endl;
        cout<<"PONSTAN"<<endl;
        cout<<"500mg"<<endl;
        cout<<"Your bill is Rs500 /-"<<endl;
        cout<<"************************"<<endl;
    }
    else if (M_medname == "10")
    {
        cout << "\nEnter Dosage (e.g 100mg, 200mg etc): ";
        getline(cin, M_dosage);
        if (M_dosage == "40mg 10 S")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer + "\n";
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "ZURIG" << endl;
            BuyingMedicine << "250mg" << endl;
            BuyingMedicine << "Your bill is Rs450 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer + "\n";
            cout<<"\n\n************************"<<endl;
            cout<<"ZURIG"<<endl;
            cout<<"250mg"<<endl;
            cout<<"Your bill is Rs450 /-"<<endl;
            cout<<"************************"<<endl; 
        }
        else if (M_dosage == "40mg 20 S")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "ZURIG" << endl;
            BuyingMedicine << "40mg 10'S" << endl;
            BuyingMedicine << "Your bill is Rs550 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"ZURIG"<<endl;
            cout<<"40mg 10'S"<<endl;
            cout<<"Your bill is Rs550 /-"<<endl;
            cout<<"************************"<<endl;
        }
        else if (M_dosage == "80mg")
        {
            cout << "Your Name: " << endl;
            getline(cin, M_medicine_buyer);
            int nameLen = M_medicine_buyer.length();

            for (int i = 0; i < nameLen; i++)
            {
                if (i == 0) //Conerting character at first index to uppercase.
                {
                    M_medicine_buyer[i] = toupper(M_medicine_buyer[i]);
                }
                else if (M_medicine_buyer[i] == ' ')
                {
                    M_medicine_buyer[i + 1] = toupper(M_medicine_buyer[i + 1]);
                }
            }
            BuyingMedicine << "\t\n\nBUYER: " + M_medicine_buyer;
            BuyingMedicine << "\n\n************************" << endl;
            BuyingMedicine << "ZURIG" << endl;
            BuyingMedicine << "40mg 10'S" << endl;
            BuyingMedicine << "Your bill is Rs600 /-" << endl;
            BuyingMedicine << "************************" << endl;
            cout << "\t\n\nBUYER: " + M_medicine_buyer;
            cout<<"\n\n************************"<<endl;
            cout<<"ZURIG"<<endl;
            cout<<"40mg 10'S"<<endl;
            cout<<"Your bill is Rs600 /-"<<endl;
            cout<<"************************"<<endl;
        }
    }
    BuyingMedicine.close();
}

// *****2.BloodBank Class*****//

//Functions of BloodBank Class

// 1. Available Blood Details
// 2. Donor and Acceptor Details

class BloodBank
{
private:
    string B_name, B_blood_group, B_cnic_no, B_age, B_contact_no;
    int B_blood_quantity;

public:
    void Available_Blood_Details();
    void Donor_and_Acceptor_Details();
    BloodBank() // Constructor
    {
        B_name = "";
        B_blood_group = "";
        B_cnic_no = "";
        B_age = "";
        B_contact_no = "";
        B_blood_quantity = 0;
    }
};

void BloodBank ::Available_Blood_Details()
{
    system("cls");
    string allDetails;
    ifstream readingFiles("Bloods_Details.txt");
    while (!readingFiles.eof())
    { // keep reading until end-of-file
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
}

void BloodBank ::Donor_and_Acceptor_Details()
{
    ofstream writingBloodsDetail("Bloods_Order.txt", ios::app);
    system("cls");
    cin.ignore();

    cout << "\n\n**************AVAILABLE BLOOD DETAILS*************" << endl;
    cout << "\n\n1)   Blood Group: A+  " << endl;
    cout << "     Available Quantity: 10 Bottles " << endl;
    cout << "     Price For 1 Bottle: 1200  " << endl;
    cout << "     Requirement Specially For Donor: Must Be Free From Any Kind Of Disease " << endl;
    cout << "     Requirement For Both Donor And Acceptor: Must Be Corona Vaccinated " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n2)   Blood Group: A- " << endl;
    cout << "     Available Quantity: 20 Bottles " << endl;
    cout << "     Price For 1 Bottle: 1200 " << endl;
    cout << "     Requirement Specially For Donor: Must Be Free From Any Kind Of Disease " << endl;
    cout << "     Requirement Specially For Both Donor And Acceptor: Must Be Corona Vaccinated " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n3)   Blood Group: B+  " << endl;
    cout << "     Available Quantity: 8 Bottles " << endl;
    cout << "     Price For 1 Bottle: 1500 " << endl;
    cout << "     Requirement Specially For Donor: Must Be Free From Any Kind Of Disease " << endl;
    cout << "     Requirement For Both Donor And Acceptor: Must Be Corona Vaccinated " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n4)   Blood Group: B-  " << endl;
    cout << "     Available Quantity: 12 Bottles " << endl;
    cout << "     Price For 1 Bottle: 2500 " << endl;
    cout << "     Requirement Specially For Donor: Must Be Free From Any Kind Of Disease " << endl;
    cout << "     Requirement For Both Donor And Acceptor: Must Be Corona Vaccinated " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n5)   Blood Group: AB+  " << endl;
    cout << "     Available Quantity: 16 Bottles " << endl;
    cout << "     Price For 1 Bottle: 1400 " << endl;
    cout << "     Requirement Specially For Donor: Must Be Free From Any Kind Of Disease " << endl;
    cout << "     Requirement For Both Donor And Acceptor: Must Be Corona Vaccinated " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n6)   Blood Group: O+  " << endl;
    cout << "     Available Quantity: 14 Bottles " << endl;
    cout << "     Price For 1 Bottle: 1600 " << endl;
    cout << "     Requirement Specially For Donor: Must Be Free From Any Kind Of Disease " << endl;
    cout << "     Requirement For Both Donor And Acceptor: Must Be Corona Vaccinated " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n7)   Blood Group: O-  " << endl;
    cout << "     Available Quantity: 15 Bottles " << endl;
    cout << "     Price For 1 Bottle: 1600 " << endl;
    cout << "     Requirement Specially For Donor: Must Be Free From Any Kind Of Disease " << endl;
    cout << "     Requirement For Both Donor And Acceptor: Must Be Corona Vaccinated  " << endl;
    cout << "======================================================================" << endl;

    cout << "\nTell your Name: ";
    getline(cin, B_name);
    writingBloodsDetail << "\n\nNAME: " + B_name << endl;

    cout << "Tell your Age: ";
    getline(cin, B_age);
    writingBloodsDetail << "AGE: " + B_age << endl;

    cout << "Tell your CNIC-NUMBER: ";
    getline(cin, B_cnic_no);
    writingBloodsDetail << "CNIC-NUMBER " + B_cnic_no << endl;

    cout << "Tell your Contact Number: ";
    getline(cin, B_contact_no);
    writingBloodsDetail << "CONTACT NUMBER: " + B_contact_no << endl;

    cout << "Tell your Blood Group (e.g. A+, B+, 0+ etc): ";
    getline(cin, B_blood_group);
    writingBloodsDetail << "BLOOD GROUP: " + B_blood_group << endl;
    if (B_blood_group == "A+")
    {
        cout << "Tell how many bottles you want ? (e.g. 1, 2,..) : ";
        cin >> B_blood_quantity;
        writingBloodsDetail << "BLOOD QUANTITY: " << B_blood_quantity;
        if (B_blood_quantity <= 10)
        {
            writingBloodsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Blood Cost = Rs "<<B_blood_quantity*1200<<"/-"<<"                    |"     <<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Blood Cost = Rs "<<B_blood_quantity*1200<<"/-"<<"                    |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired BLOOD Quantity is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;  
        }
    }
    else if (B_blood_group == "A-")
    {
        cout << "Tell how many bottles you want ? (e.g. 1, 2,..) : ";
        cin >> B_blood_quantity;
        writingBloodsDetail << "BLOOD QUANTITY: " << B_blood_quantity;
        if (B_blood_quantity <= 20)
        {
            writingBloodsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Blood Cost = Rs "<<B_blood_quantity*1200<<"/-"<<"                    |"     <<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Blood Cost = Rs "<<B_blood_quantity*1200<<"/-"<<"                    |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired BLOOD Quantity is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;  
        }
    }
    else if (B_blood_group == "B+")
    {
        cout << "Tell how many bottles you want ? (e.g. 1, 2,..) : ";
        cin >> B_blood_quantity;
        writingBloodsDetail << "BLOOD QUANTITY: " << B_blood_quantity;
        if (B_blood_quantity <= 20)
        {
            writingBloodsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Blood Cost = Rs "<<B_blood_quantity*1500<<"/-"<<"                             |"     <<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Blood Cost = Rs "<<B_blood_quantity*1500<<"/-"<<"                             |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired BLOOD Quantity is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;  
        }
    }
    else if (B_blood_group == "B-")
    {
        cout << "Tell how many bottles you want ? (e.g. 1, 2,..) : ";
        cin >> B_blood_quantity;
        writingBloodsDetail << "BLOOD QUANTITY: " << B_blood_quantity;
        if (B_blood_quantity <= 8)
        {
           writingBloodsDetail<<"\n\n|--------------------------------------------------|"<<endl;
           writingBloodsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
           writingBloodsDetail<<"| Your Blood is Rear!!                             |"<<endl;
           writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
           writingBloodsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
           writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
           writingBloodsDetail<<"| Blood Cost = Rs "<<B_blood_quantity*2500<<"/-"<<"                              |"     <<endl;
           writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
           cout<<"\n\n|--------------------------------------------------|"<<endl;
           cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
           cout<<"| Your Blood is Rear!!                             |"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"| Blood Cost = Rs "<<B_blood_quantity*2500<<"/-"<<"                              |"     <<endl;
           cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired BLOOD Quantity is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;  
        }
    }
    else if (B_blood_group == "AB+")
    {
        cout << "Tell how many bottles you want ? (e.g. 1, 2,..) : ";
        cin >> B_blood_quantity;
        writingBloodsDetail << "BLOOD QUANTITY: " << B_blood_quantity;
        if (B_blood_quantity <= 16)
        {
           writingBloodsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Blood Cost = Rs "<<B_blood_quantity*1400<<"/-"<<"                            |"     <<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
           cout<<"\n\n|--------------------------------------------------|"<<endl;
           cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"| Blood Cost = Rs "<<B_blood_quantity*1400<<"/-"<<"                            |"     <<endl;
           cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired BLOOD Quantity is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;  
        }
    }
    else if (B_blood_group == "O+")
    {
        cout << "Tell how many bottles you want ? (e.g. 1, 2,..) : ";
        cin >> B_blood_quantity;
        writingBloodsDetail << "BLOOD QUANTITY: " << B_blood_quantity;
        if (B_blood_quantity <= 14)
        {
            writingBloodsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Blood Cost = Rs "<<B_blood_quantity*1600<<"/-"<<"                           |"     <<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Blood Cost = Rs "<<B_blood_quantity*1600<<"/-"<<"                           |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired BLOOD Quantity is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;  
        }
    }
    else if (B_blood_group == "O-")
    {
        cout << "Tell how many bottles you want ? (e.g. 1, 2,..) : ";
        cin >> B_blood_quantity;
        writingBloodsDetail << "BLOOD QUANTITY: " << B_blood_quantity;
        if (B_blood_quantity <= 15)
        {
            writingBloodsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            writingBloodsDetail<<"| Blood Cost = Rs "<<B_blood_quantity*1600<<"/-"<<"                           |"     <<endl;
            writingBloodsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Blood Cost = Rs "<<B_blood_quantity*1600<<"/-"<<"                           |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired BLOOD Quantity is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;  
        }
    }
    else
    {
        cout<<"|------------------------------------------------------------|"<<endl;
        cout<<"|   SORRY!! Your Desired BLOOD Quantity is NOT AVAILABLE.    |"<<endl;
        cout<<"|        We are Unable to fulfill your Requirement!          |"<<endl;
        cout<<"|------------------------------------------------------------|"<<endl;
    }
    cin.ignore();
    writingBloodsDetail.close();
}

// *****3.Equipment Class*****//

//Functions of Equipment Class

// 1. Available Equipment Details
// 2. Buy Equipment

class Equipment
{
private:
    string E_equipment_buyer;
    int E_equip, E_equipment_quantity;

public:
    void Available_Equipment_Details();
    void Buy_Equipment();
    Equipment() // Constructor
    {
        E_equip = 0;
        E_equipment_buyer = "";
        E_equipment_quantity = 0;
    }
};

void Equipment ::Available_Equipment_Details()
{
    system("cls");
    string allDetails;
    ifstream readingFiles("Equipments_Details.txt");
    while (!readingFiles.eof())
    { // keep reading until end-of-file
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
}

void Equipment ::Buy_Equipment()
{
    ofstream writingEquipmentsDetail("Equipments_Sold.txt", ios::app);
    system("cls");
    cin.ignore();

    cout << "\n\n**************EQUIPMENTS AVAILABLE IN PHARMACY*************" << endl;
    cout << "\n\n1)   Equipment Name: INJECTION " << endl;
    cout << "     Equipment Available Quantity: 1000 Available " << endl;
    cout << "     Equipment Price: Rs.40 per Injection  " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n2)   Equipment Name: CANNULA " << endl;
    cout << "     Equipment Available Quantity: 900 Available " << endl;
    cout << "     Equipment Price: Rs.300 per Cannula  " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n3)   Equipment Name: THERMOMETER " << endl;
    cout << "     Equipment Available Quantity: 700 Available " << endl;
    cout << "     Equipment Price: Rs.250 per Thermometer  " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n4)   Equipment Name: MEASURING TAPE " << endl;
    cout << "     Equipment Available Quantity: 600 Available " << endl;
    cout << "     Equipment Price: Rs.500 per Tape " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n5)   Equipment Name: SURGICAL SCISSORS " << endl;
    cout << "     Equipment Available Quantity: 700 Available " << endl;
    cout << "     Equipment Price: Rs.100 per Scissor  " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n6)   Equipment Name: STETHOSCOPE " << endl;
    cout << "     Equipment Available Quantity: 300 Available " << endl;
    cout << "     Equipment Price: Rs.500 per Stethoscope " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n7)   Equipment Name: BANDAGE " << endl;
    cout << "     Equipment Available Quantity: 900 Available " << endl;
    cout << "     Equipment Price: Rs.150 per Bandage  " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n8)   Equipment Name: SUCTION DEVICE " << endl;
    cout << "     Equipment Available Quantity: 99 Available " << endl;
    cout << "     Equipment Price: Rs.1500 per Device  " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n9)   Equipment Name: KIDNEY DISH " << endl;
    cout << "     Equipment Available Quantity: 100 Available " << endl;
    cout << "     Equipment Price: Rs.250 per Dish  " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\n10)  Equipment Name: GAUZE SPONGE " << endl;
    cout << "     Equipment Available Quantity: 1200 Available " << endl;
    cout << "     Equipment Price: Rs.400 per Sponge  " << endl;
    cout << "======================================================================" << endl;

    cout << "\n\nSelect Equipment (1-10) from above list: ";
    cin >> E_equip;

    cout << "\nBuyer Name: ";
    cin.ignore();
    getline(cin, E_equipment_buyer);
    writingEquipmentsDetail << "\n\nBUYER NAME: " + E_equipment_buyer << endl;

    if (E_equip == 1)
    {
        cout << "Tell how many Injections do you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 1000)
        {
             writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*40<<"/-"<<"                    |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*40<<"/-"<<"                    |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 2)
    {
        cout << "Tell how many Cannulas you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 900)
        {
            writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*300<<"/-"<<"                    |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
           cout<<"\n\n|--------------------------------------------------|"<<endl;
           cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*300<<"/-"<<"                    |"     <<endl;
           cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 3)
    {
        cout << "Tell how many Thermometer you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 700)
        {
            writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*250<<"/-"<<"                             |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*250<<"/-"<<"                             |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 4)
    {
        cout << "Tell how many Measuring Tape you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 600)
        {
            writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
           writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
           writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
           writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
           writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
           writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*500<<"/-"<<"                              |"     <<endl;
           writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
           cout<<"\n\n|--------------------------------------------------|"<<endl;
           cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*500<<"/-"<<"                              |"     <<endl;
           cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 5)
    {
        cout << "Tell how many Surgical Scissors you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 700)
        {
           writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*100<<"/-"<<"                            |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*100<<"/-"<<"                            |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 6)
    {
        cout << "Tell how many Stethoscope you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 300)
        {
            writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*500<<"/-"<<"                           |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*500<<"/-"<<"                           |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 7)
    {
        cout << "Tell how many Bandage you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 900)
        {
            writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*150<<"/-"<<"                           |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*150<<"/-"<<"                           |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 8)
    {
        cout << "Tell how many Suction Device you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 99)
        {
            writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*1500<<"/-"<<"                           |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
           cout<<"\n\n|--------------------------------------------------|"<<endl;
           cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
           cout<<"|--------------------------------------------------|"<<endl;
           cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*1500<<"/-"<<"                           |"     <<endl;
           cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 9)
    {
        cout << "Tell how many Kidney Dish you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 100)
        {
            writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*250<<"/-"<<"                           |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*250<<"/-"<<"                           |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else if (E_equip == 10)
    {
        cout << "Tell how many Gauze Sponge you want ? (e.g. 1, 2,..) : ";
        cin >> E_equipment_quantity;
        writingEquipmentsDetail << "EQUIPMENT QUANTITY: " << E_equipment_quantity;
        if (E_equipment_quantity <= 1200)
        {
            writingEquipmentsDetail<<"\n\n|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            writingEquipmentsDetail<<"| Equipment Cost = Rs "<<E_equipment_quantity*400<<"/-"<<"                           |"     <<endl;
            writingEquipmentsDetail<<"|--------------------------------------------------|"<<endl;
            cout<<"\n\n|--------------------------------------------------|"<<endl;
            cout<<"| Congratulations! Your Details Are Matched!!      |"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"|***************** YOU CAN BUY IT *****************|"<<endl;
            cout<<"|--------------------------------------------------|"<<endl;
            cout<<"| Equipment Cost = Rs "<<E_equipment_quantity*400<<"/-"<<"                           |"     <<endl;
            cout<<"|--------------------------------------------------|"<<endl;
        }
        else
        {
            cout<<"\n\nSORRY!! Your Desired EQUIPMENT is NOT AVAILABLE."<<endl;
            cout<<" We are Unable to fulfill your Requirement!"<<endl;
        }
    }
    else
    {
        cout<<"\n\n|------------------------------------------------------------|"<<endl;
        cout<<"|   SORRY!! Your Desired EQUIPMENT is NOT AVAILABLE.    |"<<endl;
        cout<<"|        We are Unable to fulfill your Requirement!          |"<<endl;
        cout<<"|------------------------------------------------------------|"<<endl;
    }
    cin.ignore();
    writingEquipmentsDetail.close();
}

// /////////////////////////////// Finance Portion (HAMZA AHMED KHAN) CT-35 /////////////////////////////

// *****1.OPD Class*****//

class O_P_D
{

private:
    string O_doctors, O_patient_name, O_disease, O_report_time;

public:
    void Availability_of_Doctors();
    void Show_OPDReceipt();
    O_P_D() // Constructor
    {
        O_doctors = "";
        O_patient_name = "";
        O_disease = "";
        O_report_time = "";
    }
};

//Functions of OPD Class

// 1. Availability of Doctors
// 2. Show_Receipt

void O_P_D ::Availability_of_Doctors()
{
    system("cls");
    string allDetails;
    ifstream readingFiles("OPD_DOCTORS.txt");
    while (!readingFiles.eof())
    { // keep reading until end-of-file
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
}

void O_P_D ::Show_OPDReceipt()
{
    ofstream writingOPDDetail("OPD_RECEIPT.txt", ios::app);
    system("cls");
    cin.ignore();
    cout << "Patient Name : " << endl;
    getline(cin, O_patient_name);
    int nameLen = O_patient_name.length();

    for (int i = 0; i < nameLen; i++)
    {
        if (i == 0) //Conerting character at first index to uppercase.
        {
            O_patient_name[i] = toupper(O_patient_name[i]);
        }
        else if (O_patient_name[i] == ' ')
        {
            O_patient_name[i + 1] = toupper(O_patient_name[i + 1]);
        }
    }
    writingOPDDetail << "\t\n\nPATIENT NAME: " + O_patient_name + "\n";
    for (int i = 0; i < nameLen; i++)
    { //Generating a design
        writingOPDDetail << "=";
    }

    cout << "Enter Disease : ";
    getline(cin, O_disease);
    writingOPDDetail << "\nDISEASE: " + O_disease;

    cout << "Enter Reporting Time: ";
    getline(cin, O_report_time);
    writingOPDDetail << "\nREPORT TIME: " + O_report_time;

    cout << "\n\n1)  Dr. Nashra Ghaffar" << endl;
    cout << "  Specialization: Child Specialist" << endl;
    cout << "\n2)  Dr. Anwar Maqsood " << endl;
    cout << "  Specialization: Disease Specialist " << endl;
    cout << "\n3)  Dr. Umme Kulsoom " << endl;
    cout << "  Specialization: Dermatologist " << endl;
    cout << "\n4)  Dr. Abdul Hameed " << endl;
    cout << "  Specialization: Nephrologist " << endl;

    cout << "\nSelect Doctor from (1-4) from the above list: ";
    getline(cin, O_doctors);
    if (O_doctors == "1")
    {
        writingOPDDetail    <<"Apointed By: Dr. Nashra Ghaffar"<<endl;
        writingOPDDetail    <<"\n|-------------------------------------|"<<endl;
        writingOPDDetail    <<"|     Bill Paid = Rs /- 5000"<<"          |"<<endl;
        writingOPDDetail    <<"|-------------------------------------|"<<endl;
        cout    <<"Apointed By: Dr. Nashra Ghaffar"<<endl;
        cout    <<"\n|-------------------------------------|"<<endl;
        cout    <<"|     Bill Paid = Rs /- 5000"<<"          |"<<endl;
        cout    <<"|-------------------------------------|"<<endl;
    }
    else if (O_doctors == "2")
    {
        writingOPDDetail    <<"\nApointed By: Dr. Anwar Maqsood"<<endl;
        writingOPDDetail    <<"\n|-------------------------------------|"<<endl;
        writingOPDDetail    <<"|     Bill Paid = Rs /- 5000"<<"          |"<<endl;
        writingOPDDetail    <<"|-------------------------------------|"<<endl;
        cout    <<"\nApointed By: Dr. Anwar Maqsood"<<endl;
        cout    <<"\n|-------------------------------------|"<<endl;
        cout    <<"|     Bill Paid = Rs /- 5000"<<"          |"<<endl;
        cout    <<"|-------------------------------------|"<<endl;
    }
    else if (O_doctors == "3")
    {
        writingOPDDetail    <<"Apointed By: Dr. Umme Kulsoomd"<<endl;
        writingOPDDetail    <<"\n|-------------------------------------|"<<endl;
        writingOPDDetail    <<"|     Bill Paid = Rs /- 6500"<<"          |"<<endl;
        writingOPDDetail    <<"|-------------------------------------|"<<endl;
        cout    <<"Apointed By: Dr. Umme Kulsoomd"<<endl;
        cout    <<"\n|-------------------------------------|"<<endl;
        cout    <<"|     Bill Paid = Rs /- 6500"<<"          |"<<endl;
        cout    <<"|-------------------------------------|"<<endl;
    }
    else if (O_doctors == "4")
    {
        writingOPDDetail    <<"Apointed By: Dr. Abdul Hameed"<<endl;
        writingOPDDetail    <<"\n|-------------------------------------|"<<endl;
        writingOPDDetail    <<"|     Bill Paid = Rs /- 6000"<<"          |"<<endl;
        writingOPDDetail    <<"|-------------------------------------|"<<endl;
        cout    <<"Apointed By: Dr. Abdul Hameed"<<endl;
        cout    <<"\n|-------------------------------------|"<<endl;
        cout    <<"|     Bill Paid = Rs /- 6000"<<"          |"<<endl;
        cout    <<"|-------------------------------------|"<<endl;
    }

    cin.ignore();
    writingOPDDetail.close();
}

// *****2.Emergency Class*****//

class Emergency
{

private:
    string E_doctors, E_patient_name, E_patient_id, E_address, E_CNICnumber, E_contactnumber, E_type_of_case, E_report_time;

public:
    void Doctors_Available();
    void Show_EmergencyReceipt();
    Emergency() // Constructor
    {
        E_doctors = "";
        E_patient_name = "";
        E_patient_id = "";
        E_address = "";
        E_CNICnumber = "";
        E_contactnumber = "";
        E_type_of_case = "";
        E_report_time = "";
    }
};

//Functions of Emergency Class

// 1. Doctors Available
// 2. Show Receipt

void Emergency ::Doctors_Available()
{
    system("cls");
    string allDetails;
    ifstream readingFiles("EMERGENCY_DOCTORS.txt");
    while (!readingFiles.eof())
    { // keep reading until end-of-file
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
}

void Emergency ::Show_EmergencyReceipt()
{
    ofstream writingEMERGENCYDetail("EMERGENCY_RECEIPT.txt", ios::app);
    system("cls");
    cin.ignore();

    cout << "Patient Name : " << endl;
    getline(cin, E_patient_name);
    int nameLen = E_patient_name.length();

    for (int i = 0; i < nameLen; i++)
    {
        if (i == 0) //Conerting character at first index to uppercase.
        {
            E_patient_name[i] = toupper(E_patient_name[i]);
        }
        else if (E_patient_name[i] == ' ')
        {
            E_patient_name[i + 1] = toupper(E_patient_name[i + 1]);
        }
    }
    writingEMERGENCYDetail << "\t\n\nPATIENT NAME: " + E_patient_name + "\n";
    for (int i = 0; i < nameLen; i++)
    { //Generating a design
        writingEMERGENCYDetail << "=";
    }

    cout << "ID : " << endl;
    getline(cin, E_patient_id);
    writingEMERGENCYDetail << "\nID: " + E_patient_id;

    cout << "Address : " << endl;
    getline(cin, E_address);
    writingEMERGENCYDetail << "\nADDRESS: " + E_address;

    cout << "CNIC Number : " << endl;
    getline(cin, E_CNICnumber);
    writingEMERGENCYDetail << "\nCNIC NUMBER: " << E_CNICnumber;

    cout << "Contact Number : " << endl;
    getline(cin, E_contactnumber);
    writingEMERGENCYDetail << "\nCONTACT NUMBER: " << E_contactnumber;

    cout << "Enter Reporting Time: ";
    getline(cin, E_report_time);
    writingEMERGENCYDetail << "\nREPORT TIME: " + E_report_time;

    cout << "Enter Emergency Case : " << endl;
    getline(cin, E_type_of_case);
    writingEMERGENCYDetail << "\nCase: " + E_type_of_case;

    cout << "\n\n1) Dr. M. Ali Mughal" << endl;
    cout << "  Specializations: Trauma Surgeon, Chronic Obstructive Pulmonary Disease, Dementia, Assesment Of Hyper Tension And Ischemic Diseases" << endl;
    cout << "\n2)  Dr. Dania Aamir " << endl;
    cout << "  Specializations: Pregnancy Care (Antenatal & Post-natal), Chest Pain, Respiratory System, Neurological System " << endl;
    cout << "\n3) Dr. S. Bilal Qureshi " << endl;
    cout << "  Specializations: Cerebrovascular Accident, Minor Surgeries, Pituitary Disease, Emphysema, Irritable Bowel Syndrome, Vaccination " << endl;
    cout << "\n4)  Dr. Abdullah Javaid " << endl;
    cout << "  Specializations: Accident & Emergency, Minor Surgeries , Biopsy & Autopsy of all Types, Vaccination " << endl;
    cout << "\n4)  Dr. M. Usman Akram " << endl;
    cout << "  Specializations: Emergency Medicine Specialist " << endl;

    cout << "\nSelect Doctor from (1-5) from the above list: ";
    getline(cin, E_doctors);
    if (E_doctors == "1")
    {
        writingEMERGENCYDetail   <<"\nTreatment Performed By: Dr. M. Ali Mughal"<<endl;
        writingEMERGENCYDetail << "\n|-------------------------------------|"<<endl;
        writingEMERGENCYDetail <<"|     Doctor's Fees = 3500            |"<<endl;
        writingEMERGENCYDetail <<"|     Room Charges = 1500             |"<<endl;
        writingEMERGENCYDetail <<"|     Total bill paid = Rs /- 4000"<<"   |"<<endl;
        writingEMERGENCYDetail <<"|-------------------------------------|"<<endl;
        cout   <<"\nTreatment Performed By: Dr. M. Ali Mughal"<<endl;
        cout << "\n|-------------------------------------|"<<endl;
        cout <<"|     Doctor's Fees = 3500            |"<<endl;
        cout <<"|     Room Charges = 1500             |"<<endl;
        cout <<"|     Total bill paid = Rs /- 4000"<<"   |"<<endl;
        cout <<"|-------------------------------------|"<<endl;
    }
    else if (E_doctors == "2")
    {
        writingEMERGENCYDetail   <<"\nTreatment Performed By:  Dr. Dania Aamir"<<endl;
        writingEMERGENCYDetail<<"\n|-------------------------------------|"<<endl;
        writingEMERGENCYDetail    <<"|     Doctor's Fees = 5000            |"<<endl;
        writingEMERGENCYDetail    <<"|     Room Charges = 1500             |"<<endl;
        writingEMERGENCYDetail    <<"|     Total bill paid = Rs /- 6500"<<"   |"<<endl;
        writingEMERGENCYDetail    <<"|-------------------------------------|"<<endl;
        cout   <<"\nTreatment Performed By:  Dr. Dania Aamir"<<endl;
        cout<<"\n|-------------------------------------|"<<endl;
        cout    <<"|     Doctor's Fees = 5000            |"<<endl;
        cout    <<"|     Room Charges = 1500             |"<<endl;
        cout    <<"|     Total bill paid = Rs /- 6500"<<"   |"<<endl;
        cout    <<"|-------------------------------------|"<<endl;
    }
    else if (E_doctors == "3")
    {
        writingEMERGENCYDetail   <<"\nTreatment Performed By: Dr. S. Bilal Qureshi"<<endl;
        writingEMERGENCYDetail<<"\n|-------------------------------------|"<<endl;
        writingEMERGENCYDetail    <<"|     Doctor's Fees = 4000            |"<<endl;
        writingEMERGENCYDetail    <<"|     Room Charges = 1500             |"<<endl;
        writingEMERGENCYDetail    <<"|     Total bill paid = Rs /- 5500"<<"   |"<<endl;
        writingEMERGENCYDetail    <<"|-------------------------------------|"<<endl;
        cout   <<"\nTreatment Performed By: Dr. S. Bilal Qureshi"<<endl;
        cout<<"\n|-------------------------------------|"<<endl;
        cout    <<"|     Doctor's Fees = 4000            |"<<endl;
        cout    <<"|     Room Charges = 1500             |"<<endl;
        cout    <<"|     Total bill paid = Rs /- 5500"<<"   |"<<endl;
        cout    <<"|-------------------------------------|"<<endl;
    }
    else if (E_doctors == "4")
    {
        writingEMERGENCYDetail   <<"\nTreatment Performed By: Dr. Abdullah Javaid"<<endl;
        writingEMERGENCYDetail<<"\n|-------------------------------------|"<<endl;
        writingEMERGENCYDetail    <<"|     Doctor's Fees = 5000            |"<<endl;
        writingEMERGENCYDetail    <<"|     Room Charges = 1500             |"<<endl;
        writingEMERGENCYDetail    <<"|     Total bill paid = Rs /- 5500"<<"   |"<<endl;
        writingEMERGENCYDetail    <<"|-------------------------------------|"<<endl;
        cout   <<"\nTreatment Performed By: Dr. Abdullah Javaid"<<endl;
        cout<<"\n|-------------------------------------|"<<endl;
        cout    <<"|     Doctor's Fees = 5000            |"<<endl;
        cout    <<"|     Room Charges = 1500             |"<<endl;
        cout    <<"|     Total bill paid = Rs /- 5500"<<"   |"<<endl;
        cout    <<"|-------------------------------------|"<<endl;
    }
    else if (E_doctors == "5")
    {
        writingEMERGENCYDetail   <<"\nTreatment Performed By: Dr. M. Usman Akram"<<endl;
        writingEMERGENCYDetail<<"\n|-------------------------------------|"<<endl;
        writingEMERGENCYDetail    <<"|     Doctor's Fees = 3000            |"<<endl;
        writingEMERGENCYDetail    <<"|     Room Charges = 1500             |"<<endl;
        writingEMERGENCYDetail    <<"|     Total bill paid = Rs /- 4500"<<"   |"<<endl;
        writingEMERGENCYDetail    <<"|-------------------------------------|"<<endl;
        cout   <<"\nTreatment Performed By: Dr. M. Usman Akram"<<endl;
        cout<<"\n|-------------------------------------|"<<endl;
        cout    <<"|     Doctor's Fees = 3000            |"<<endl;
        cout    <<"|     Room Charges = 1500             |"<<endl;
        cout    <<"|     Total bill paid = Rs /- 4500"<<"   |"<<endl;
        cout    <<"|-------------------------------------|"<<endl;
    }
    cin.ignore();
    writingEMERGENCYDetail.close();
}

// *****3.Laboratory Class*****//

class Laboratory
{

private:
    string L_patient_name, L_patient_id, L_report_title, L_test_results, L_search_report;

public:
    void Add_Reports();
    void Delete_Report();
    void Show_LabReceipt();
    Laboratory() // Constructor
    {
        L_patient_name = "";
        L_patient_id = "";
        L_report_title = "";
        L_test_results = "";
        L_search_report = "";
    }
};

//Functions of Laboratory Class

// 1. Add Reports
// 2. Delete Report
// 3. Show Receipt

void Laboratory ::Add_Reports()
{
    ofstream writingLabDetail("LABORATORY_ADDREPORTS.txt", ios::app);
    system("cls");
    cout << "ID: " << endl;
    cin.ignore();

    getline(cin, L_patient_id);
    writingLabDetail << "\n\n" + L_patient_id + "\n";
    int nameLen = L_patient_id.length();
    for (int i = 0; i < nameLen; i++)
    { //Generating a design
        writingLabDetail << "=";
    }
    
    cout << "Patient Name: " << endl;
    getline(cin, L_patient_name);
    int nameLe = L_patient_name.length();

    for (int i = 0; i < nameLe; i++)
    {
        if (i == 0) //Conerting character at first index to uppercase.
        {
            L_patient_name[i] = toupper(L_patient_name[i]);
        }
        else if (L_patient_name[i] == ' ')
        {
            L_patient_name[i + 1] = toupper(L_patient_name[i + 1]);
        }
    }
    writingLabDetail << "\t\n\nPatient Name: " + L_patient_name + "\n";

    cout << "Enter Report Title: ";
    getline(cin, L_report_title);
    writingLabDetail << "\nReport Title: " + L_report_title;

    cout << "Enter Test Results: ";
    getline(cin, L_test_results);
    writingLabDetail << "\nTest Results: " + L_test_results;

    cin.ignore();
    writingLabDetail.close();
}

void Laboratory ::Delete_Report()
{

    string line, L_patient_id;
    int found = 0;
    ifstream readReport("LABORATORY_ADDREPORTS.txt");
    ofstream writeNewReport("tempReport.txt");
    cout << "\n\n\t\t\tEnter ID of the Patient you want to delete: ";
    cin.ignore();
    getline(cin, L_patient_id);
    int skip = 0;
    while (getline(readReport, line))
    {
        if (L_patient_id == line)
        {
            found = 1;
        }
        if ((line != L_patient_id) && !(skip > 0))
        {
            writeNewReport << line << endl;
        }
        else
        {
            if (skip == 0)
            {
                skip = 10;
            }
            else
            {
                --skip;
            }
        }
    }

    if (found == 0)
    {
        cout << "\n\t\t\t Sorry !! No Report found .." << endl;
    }
    else
    {
        cout << "\n\n\t\t\t ***    Report Deleted Successfully    ***" << endl;
    }
    readReport.close();
    writeNewReport.close();
    remove("LABORATORY_ADDREPORTS.txt");
    rename("tempReport.txt", "LABORATORY_ADDREPORTS.txt");
}

void Laboratory ::Show_LabReceipt()
{
    system("cls");
    cin.ignore();
    cout << "\nLABORATORY TESTS " << endl;
    cout << "\n\n1)  BloodTest & Anatomic Pathology" << endl;
    cout << "2)  UltraSound USG" << endl;
    cout << "3)  Cancer Diagnosis" << endl;
    cout << "4)  Orthopedics and XRAYs" << endl;
    cout << "5)  Eye-Test & Retina Examination" << endl;
    cout << "6)  CT Scan" << endl;
    cout << "7)  Dental Issues & Surgery" << endl;
    cout << "8)  Psychotherapy" << endl;
    cout << "9)  Endocrinology" << endl;
    cout << "10)  Drug Screening with Enzyme Immunoassay" << endl;

    cout << "\nSelect from (1-10) Which LABtest You Have Performed  OR  Which LABtest You Want To Perform: ";
    getline(cin, L_search_report);
    if (L_search_report == "1")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|      BLOODTEST & ANATOMIC PATHOLOGY:      |"<<endl
                <<"| Laboratory Prof: Dr. Abdul Ghafoor        |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 5000"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "2")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|              ULTRASOUND USG:              |"<<endl
                <<"| Laboratory Prof: Dr. M. Ghazanfar Iqbal   |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 6000"<<"      |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "3")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|             CANCER DIAGNOSIS:             |"<<endl
                <<"| Laboratory Prof: Dr. M. Mustafa Kamal     |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 8000"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "4")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|           ORTHOPEDICS AND XRAYS:          |"<<endl
                <<"| Laboratory Prof: Dr. K.K. Nizamuddin      |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 5500"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "5")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|       EYE-TEST & RETINA EXAMINATION:      |"<<endl
                <<"| Laboratory Prof: Dr. Yousuf Rizvi         |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 5000"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "6")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|                  CT SCAN:                 |"<<endl
                <<"| Laboratory Prof: Dr. Abdul Moiz Hashmi    |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 8000"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "7")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|         DENTAL ISSUES & SURGERY:          |"<<endl
                <<"| Laboratory Prof: Dr. Richard Harrison     |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 6500"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "8")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|               PSYCHOTHERAPY:              |"<<endl
                <<"| Laboratory Prof: Dr. Jahangir Khan        |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 8000"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "9")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|                ENDOCRINOLOGY:             |"<<endl
                <<"| Laboratory Prof: Dr. Ghulam Mohammad      |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 7000"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
    else if (L_search_report == "10")
    {
        cout<<"\n\n|-------------------------------------------|"<<endl
                <<"|  DRUG SCREENING WITH ENZYME IMMUNOASSAY:  |"<<endl
                <<"| Laboratory Prof: Dr. M. Haseeb Soomro     |"<<endl
                <<"|-------------------------------------------|"<<endl
                <<"|     Your have to pay Rs /- 4000"<<"           |"<<endl
                <<"|-------------------------------------------|"<<endl;
    }
}

/////////////////////////////// FEEDBACK Portion (NASHRA GHAFFAR) CT-32 /////////////////////////////

// *****1.HOSPITAL FEEDBACK Class*****//
class Hospital_Feedback
{

private:
    string feedbackerName = "";
    string HospitalFeedback = "";

public:
    void addFeedback();
    void showFeedback();
};

// 1. Add Feedback
// 2. Show Feedback

//1.

void Hospital_Feedback ::addFeedback()
{
    int nameLen = 0;
    cout << "\t\t\t > FEEDBACK FORM <" << endl;
    cout << "\t\t\t =================" << endl;
    cout << "\n\n\t\t\tPress Enter Key to continue..." << endl;
    cin.ignore();
    cout << "\n\n\t\t\t Enter your name first : " << endl;
    cout << "\n\t\t\t NAME : ";
    getline(cin, feedbackerName);
    nameLen = feedbackerName.length();

    ofstream writeHospitalFeedback("HospitalFeedback.txt", ios::app);
    cout << "\n\n\t\t\tPlease write your Feedback here..." << endl;
    // cin.ignore();
    getline(cin, HospitalFeedback);
    writeHospitalFeedback << "\nFeedback by : " << feedbackerName << endl;
    for (int i = 0; i < nameLen + 14; i++)
    {
        //Generating a design
        writeHospitalFeedback << "=";
    }

    writeHospitalFeedback << "\n\n"
                          << HospitalFeedback << endl;
    writeHospitalFeedback.close();
}

//2.

void Hospital_Feedback ::showFeedback()
{

    cout << "\n\n\t\t\t\t\tFeedbacks" << endl;
    cout << "\t\t\t\t\t=========" << endl;
    // string allFeedback="";
    string allDetails;
    ifstream readingFiles("HospitalFeedback.txt");
    while (!readingFiles.eof())
    {
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
    readingFiles.close();
}

// *****2.DOCTORS FEEDBACK Class*****//

class Doctors_Feedback
{
private:
    string feedbackerName;

protected:
    string docFeedback;

public:
    void addFeedback();
    void showFeedback();
};
// 1. Add Feedback
// 2. Show Feedback

//1.

void Doctors_Feedback ::addFeedback()
{
    int nameLen = 0;
    cout << "\t\t\t > FEEDBACK FORM <" << endl;
    cout << "\t\t\t =================" << endl;
    cout << "\n\n\t\t\tPress Enter Key to continue..." << endl;
    cin.ignore();
    cout << "\n\t\t\t Enter your name first : " << endl;
    cout << "\n\t\t\t NAME : ";
    getline(cin, feedbackerName);
    nameLen = feedbackerName.length();
    // cin.ignore();
    ofstream writeDocFeedback("DoctorFeedback.txt", ios::app);
    cout << "\n\n\t\t\tPlease write your Feedback here..." << endl;
    getline(cin, docFeedback);
    writeDocFeedback << "\n\nFeedback by : " << feedbackerName << endl;
    for (int i = 0; i < nameLen + 14; i++)
    { //Generating a design
        writeDocFeedback << "=";
    }

    writeDocFeedback << "\n\n"
                     << docFeedback << endl;
    writeDocFeedback.close();
}

//2.

void Doctors_Feedback ::showFeedback()
{
    // system("cls");
    cout << "\t\t\t\t\tFeedbacks For Our Amazing Doctors" << endl;
    cout << "\t\t\t\t\t---------------------------------" << endl;
    string allDetails;
    ifstream readingFiles("DoctorFeedback.txt");
    while (!readingFiles.eof())
    {
        getline(readingFiles, allDetails);
        cout << "\t\t" << allDetails << endl;
    }
    readingFiles.close();
}

// *****3.SIDEWORKERS FEEDBACK Class*****//

class Sideworkers_Feedback
{
private:
    string feedbackerName;
    string sidewFeedback;

public:
    void addFeedback();
    void showFeedback();
};
// 1. Add Feedback
// 2. Show Feedback

//1.

void Sideworkers_Feedback ::addFeedback()
{
    // system("cls");
    int nameLen = 0;
    cout << "\t\t\t > FEEDBACK FORM <" << endl;
    cout << "\t\t\t =================" << endl;
    cout << "\n\n\t\t\tPress Enter Key to continue..." << endl;
    cin.ignore();
    cout << "\n\t\t\t Enter your name first : " << endl;
    cout << "\n\t\t\t NAME : ";
    getline(cin, feedbackerName);
    nameLen = feedbackerName.length();
    ofstream writeSidewFeedback("SideworkerFeedback.txt", ios::app);
    cout << "\n\n\t\t\tPlease write your Feedback here..." << endl;
    getline(cin, sidewFeedback);
    writeSidewFeedback << "\nFeedback by : " << feedbackerName << endl;
    for (int i = 0; i < nameLen + 14; i++)
    { //Generating a design
        writeSidewFeedback << "=";
    }

    writeSidewFeedback << "\n\n"
                       << sidewFeedback << endl;
    writeSidewFeedback.close();
}

//2.

void Sideworkers_Feedback ::showFeedback()
{
    cout << "\n\n\t\t\tFeedbacks" << endl;
    cout << "\t\t\t=========" << endl;
    // string allFeedback="";
    string allDetails;
    ifstream readingFiles("SideworkerFeedback.txt");
    while (!readingFiles.eof())
    {
        getline(readingFiles, allDetails);
        cout << allDetails << endl;
    }
    readingFiles.close();
}

// ----------------------------    HOSPITAL MANAGEMENT SYSTEM CLASS   -------------------------------------

class HOSPITAL_MANAGEMENT_SYSTEM
{
    private:
    //Details obj
        Doctors_Details objDD;
        Patient_Details objPD;
        SideWorker_Details objSD;
    //Feedbacks Obj
        Hospital_Feedback objHF;
        Doctors_Feedback objDF;
        Sideworkers_Feedback objSF;
    //Management Objects
        Ambulance_management objAM;
        Room_management objRM;
        Staff_Management objSM;
    //Pharmacy Objects
        Medicine objMed;
        BloodBank objBB;
        Equipment objEquip; 
    //Finance Objects
        O_P_D objOPD; 
        Emergency objEme;
        Laboratory objLab;






public:
    void welcomePage()
    {
        system("cls");
        cout << "\n\n\n\n\n\t\t\t\t\t----------------------------------------------" << endl;
        cout << "\t\t\t\t\t|  WELCOME TO DUA HOSPITAL MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t\t\t----------------------------------------------" << endl;
        cout << "\nHospital, an institution that is built, staffed, and equipped for the diagnosis of disease; for the treatment, both medical and surgical, of the sick and the injured; and for their housing during this process. The modern hospital also often serves as a centre for investigation and for teaching.To better serve the wide-ranging needs of the community, the modern hospital has often developed outpatient facilities, as well as emergency, psychiatric, and rehabilitation services. In addition, “bedless hospitals” provide strictly ambulatory (outpatient) care and day surgery. Patients arrive at the facility for short appointments. They may also stay for treatment in surgical or medical units for part of a day or for a full day, after which they are discharged for follow-up by a primary care health provider.Hospitals have long existed in most countries. Developing countries, which contain a large proportion of the world’s population, generally do not have enough hospitals, equipment, and trained staff to handle the volume of persons who need care. Thus, people in these countries do not always receive the benefits of modern medicine, public health measures, or hospital care, and they generally have lower life expectancies." << endl;
        cout << "\n\t\t\tI deem in the duty of every man to devote a certain portion of his income for charitable \n " << endl;
        cout << "\t\tpurposes; and that it is his further duty to see it so applied; to do the most good of which it is capable" << endl;
        // cin.ignore();

        getch();
        cout << "\n\n\t\t\tHello ! Let's Press Enter Key to move further...." << endl;
        loginPage();
    }

    //Title

    void title()
    {
        system("cls");
        cout << "\n\t\t\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\t\t>> DUA HOSPITAL MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t------------------------------------ \n\n\n"
             << endl;
    }

    // Portal Login Page

    void loginPage()
    {
        cin.ignore();
        system("cls");
        title();
        string username = "", password = "";
        string st1, st2;
        cout << "\t\t\t => Enter your Username and Password" << endl;
        cout << "Press Enter key to continue .. " << endl;
        cin.ignore();
        cout << "\n\n \t \t \t USERNAME:  ";
        getline(cin, username);
        cout << "\n \t \t \t PASSWORD:  ";
        getline(cin, password);
        ifstream read("Admin.txt");
        getline(read, st1);
        getline(read, st2);
        if (username == st1 && password == st2)
        {

            cout << "\n\n\n\t\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t\t";
            for (int a = 1; a < 8; a++)
            {
                Sleep(500);
                cout << "...";
            }
            cout << "\n\n\t\t\t Login Successful !!! \n\n\t\t\t Press Enter Key to continue...";
            // system("PAUSE");
            // system("cls");
            getch();
            menuPage();
        }
        else
        {

            cout << "\n\n\n\t\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t\t";
            for (int a = 1; a < 8; a++)
            {
                Sleep(500);
                cout << "...";
            }
            cout << "\n\n\t\t\t Invalid Username or Password !! Try again ..." << endl;
            getch();
            goto jump;
        }
    jump:
    {
        system("cls");
        title();
        cin.ignore();
        cout << "\n\n\t\t\t => Enter your Username and Password" << endl;
        cout << "\n\n \t \t \t USERNAME:  ";
        getline(cin, username);
        cout << "\n \t \t \t PASSWORD:  ";
        getline(cin, password);
        ifstream read("Admin.txt");
        getline(read, st1);
        getline(read, st2);
        if (username == st1 && password == st2)
        {

            cout << "\n\n\n\t\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t\t";
            for (int a = 1; a < 8; a++)
            {
                Sleep(500);
                cout << "...";
            }
            cout << "\n\n\t\t\t Login Successful !!! \n\n\t\t\t Press Enter Key to continue...";
            getch();
            menuPage();
        }
        else

        {
            cout << "\n\n\n\t\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t\t";
            for (int a = 1; a < 8; a++)
            {
                Sleep(500);
                cout << "...";
            }
            cout << "\n\n\t\t\t Invalid Username or Password !! Try again ..." << endl;
            getch();
            goto jump;
        }
    }
    }

    // DOCTOR DETAILS MENU PAGE

    void DoctorDetail()
    {
        system("cls");
        int optD = 0;
        title();
        cout << "\n\n\t\t\t1. Recruit New Doctor \n"
             << endl;
        cout << "\t\t\t2. Show Doctor Details\n"
             << endl;
        cout << "\t\t\t3. Delete Doctor Detail\n"
             << endl;
        cout << "\t\t\t4. Back to Details Menu\n"
             << endl;
        cout << "\t\t\t5. Logout\n " << endl;
        cout << "\n\nSelect any one option (1-5)" << endl;
        cin >> optD;
        if (optD == 1)
        {
            system("cls");
            title();
            // Doctors_Details obj;
            objDD.getDocDetails();
            cout << "\t\t\t*** Details Added Successfully *** " << endl;
            cout << "\n\t\t\tPress Enter Key to go back to the menu ..." << endl;
            getch();
            DoctorDetail();
        }
        else if (optD == 2)
        {
            system("cls");
            title();
            objDD.showDocDetails();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu ..." << endl;
            getch();
            DoctorDetail();
        }
        else if (optD == 3)
        {
            system("cls");
            title();
            objDD.removeDocDetail();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu ..." << endl;
            getch();
            DoctorDetail();
        }

        else if (optD == 4)
        {
            system("cls");
            title();
            details();
        }
        else if (optD == 5)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\t ***  Logout Successfully *** \n\n\t\t\t Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // PATIENT DETAILS MENU PAGE

    void PatientDetail()
    {
        system("cls");
        int optp = 0;
        title();
        cout << "\n\n\t\t\t1. Admit New Patient\n"
             << endl;
        cout << "\t\t\t2. Show Patient Details\n"
             << endl;
        cout << "\t\t\t3. Delete Patient Details\n"
             << endl;
        cout << "\t\t\t4. Back to Details Menu\n"
             << endl;
        cout << "\t\t\t5. Logout \n"
             << endl;
        cout << "\n\nSelect any one option (1-5)" << endl;
        cin >> optp;
        if (optp == 1)
        {
            system("cls");
            title();
            objPD.getPatDetails();
            cout << "\n\n\t\t\t ***    Details Added Successfully   ***" << endl;
            cout << "\n\t\t\tPress Enter Key to go back to the menu ..." << endl;

            getch();
            PatientDetail();
        }
        else if (optp == 2)
        {
            system("cls");
            title();
            objPD.showPatDetails();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu ..." << endl;
            getch();
            PatientDetail();
        }
        else if (optp == 3)
        {
            system("cls");
            title();
            objPD.removePatDetail();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu ..." << endl;
            getch();
            PatientDetail();
        }
        else if (optp == 4)
        {
            system("cls");
            title();
            details();
        }
        else if (optp == 5)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\t ***  Logout Successfully *** \n\n\t\t\t Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // SIDEWORKER DETAILS MENU PAGE

    void SideworkerDetail()
    {
        system("cls");
        int optS = 0;
        title();
        cout << "\n\n\t\t\t\t1. Recruit New Sideworker\n"
             << endl;
        cout << "\t\t\t\t2. Show Sideworker Details\n"
             << endl;
        cout << "\t\t\t\t3. Delete Sideworker Detail\n"
             << endl;
        cout << "\t\t\t\t4. Back to Details Menu\n"
             << endl;
        cout << "\t\t\t\t5. Logout \n"
             << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> optS;
        if (optS == 1)
        {
            system("cls");
            title();

            // Doctors_Details obj;
            objSD.getSWDetails();
            cout << "\n\n\t\t\t ***    Details Added Successfully   ***" << endl;
            cout << "\n\t\t\tPress Enter Key to go back to the menu ..." << endl;
            getch();
            SideworkerDetail();
        }
        else if (optS == 2)
        {
            system("cls");
            title();
            objSD.showSWDetails();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu ..." << endl;
            getch();
            SideworkerDetail();
        }
        else if (optS == 3)
        {
            system("cls");
            title();
            objSD.removeSWDetail();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu ..." << endl;
            getch();
            SideworkerDetail();
        }
        else if (optS == 4)
        {
            system("cls");
            title();
            details();
        }
        else if (optS == 5)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\t ***  Logout Successfully *** \n\n\t\t\t Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // HOSPITAL FEEDBACK MENU PAGE
    void HospitalFeedback()
    {
        system("cls");
        int optD = 0;
        title();
        cout << "\n\n\t\t\t1. Give Feedback " << endl;
        cout << "\n\t\t\t2. Show Feedback" << endl;
        cout << "\n\t\t\t3. Back to Feedback Menu" << endl;
        cout << "\n\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> optD;
        if (optD == 1)
        {
            system("cls");
            title();
            objHF.addFeedback();
            cout << "\n\n\t\t\tFeedback added Successfully..!! \n\n\t\t\t Press Enter Key to go back to the menu" << endl;
            getch();
            HospitalFeedback();
        }
        else if (optD == 2)
        {
            system("cls");
            title();
            objHF.showFeedback();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            HospitalFeedback();
        }
        else if (optD == 3)
        {
            system("cls");
            title();
            feedbacks();
        }
        else if (optD == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // DOCTORS FEEDBACK MENU PAGE

    void DoctorsFeedback()
    {
        system("cls");
        int optD = 0;
        title();
        cout << "\n\n\t\t\t1. Give Feedback " << endl;
        cout << "\n\t\t\t2. Show Feedback" << endl;
        cout << "\n\t\t\t3. Back to Feedback Menu" << endl;
        cout << "\n\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> optD;
        if (optD == 1)
        {
            system("cls");
            title();
            // Doctors_Details obj;
            objDF.addFeedback();
            cout << "\n\n\t\t\tFeedback added Successfully..!! \n\n\t\t\t Press Enter Key to go back to the menu" << endl;
            getch();
            DoctorsFeedback();
        }
        else if (optD == 2)
        {
            system("cls");
            title();
            objDF.showFeedback();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            DoctorsFeedback();
        }
        else if (optD == 3)
        {
            system("cls");
            title();
            feedbacks();
        }
        else if (optD == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    //SIDEWORKERS FEEDBACK MENU PAGE

    void SideworkersFeedback()
    {
        system("cls");
        int optD = 0;
        title();
        cout << "\n\n\t\t\t1. Give Feedback " << endl;
        cout << "\n\t\t\t2. Show Feedback" << endl;
        cout << "\n\t\t\t3. Back to Feedback Menu" << endl;
        cout << "\n\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> optD;
        if (optD == 1)
        {
            // Doctors_Details obj;
            system("cls");
            title();
            objSF.addFeedback();
            cout << "\n\n\t\t\tFeedback added Successfully..!! \n\n\t\t\t Press Enter Key to go back to the menu" << endl;
            getch();
            SideworkersFeedback();
        }
        else if (optD == 2)
        {
            system("cls");
            title();
            objSF.showFeedback();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            SideworkersFeedback();
        }
        else if (optD == 3)
        {
            system("cls");
            title();
            feedbacks();
        }
        else if (optD == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    //Ambulamce Management Menu Page

    void AmbulanceManagement()
    {
        system("cls");
        int optD = 0;
        title();
        cout << "\n\n\t\t\t1. Register Ambulance" << endl;
        cout << "\n\t\t\t2. Show Ambulances " << endl;
        cout << "\n\t\t\t3. Register Ambulance Driver" << endl;
        cout << "\n\t\t\t4. Show Ambulance Drivers " << endl;
        cout << "\n\t\t\t5. Back to Management Menu" << endl;
        cout << "\n\t\t\t6. Logout " << endl;
        cout << "\n\nSelect any one option (1-6)" << endl;
        cin >> optD;
        // Sideworkers_Feedback objS;
        if (optD == 1)
        {
            system("cls");
            title();
            objAM.register_ambulance();
            cout << "\n\n\t\t\tAmbulance Registered Successfully..!! \n\n\t\t\t Press Enter Key to go back to the menu" << endl;
            getch();
            AmbulanceManagement();
        }
        else if (optD == 2)
        {
            system("cls");
            title();
            objAM.show_ambulance();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            AmbulanceManagement();
        }
        else if (optD == 3)
        {
            system("cls");
            title();
            objAM.add_driver();
            cout << "\n\n\t\t\tAmbulance Driver Registered Successfully..!! \n\n\t\t\t Press Enter Key to go back to the menu" << endl;
            getch();
            AmbulanceManagement();
        }
        else if (optD == 4)
        {
            system("cls");
            title();
            objAM.show_driver();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            AmbulanceManagement();
        }

        else if (optD == 5)
        {
            system("cls");
            title();
            management();
        }
        else if (optD == 6)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }
    //Room Management Menu Page

    void RoomManagement()
    {
        system("cls");
        int optD = 0;
        title();
        cout << "\n\n\t\t\t1. Show Rooms Status " << endl;
        cout << "\n\t\t\t2. Admit Patient" << endl;
        cout << "\n\t\t\t3. Discharge Patient" << endl;
        cout << "\n\t\t\t4. Back to Management Menu" << endl;
        cout << "\n\t\t\t5. Logout " << endl;
        cout << "\n\nSelect any one option (1-5)" << endl;
        cin >> optD;
        // Sideworkers_Feedback objS;
        if (optD == 1)
        {
            system("cls");
            title();
            objRM.showRoomDetails();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            RoomManagement();
        }
        else if (optD == 2)
        {
            system("cls");
            title();
            objRM.admitPatient();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            RoomManagement();
        }
         else if (optD == 3)
        {
            system("cls");
            title();
            objRM.dischargePatient();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            RoomManagement();
        }
        else if (optD == 4)
        {
            system("cls");
            title();
            management();
        }
        else if (optD == 5)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }
    //Staff Management Menu Page

    void StaffManagement()
    {
        system("cls");
        int optD = 0;
        title();
        cout << "\n\n\t\t\t1. Show All Staff Details" << endl;
        cout << "\n\t\t\t2. Delete All Stafff Details" << endl;
        cout << "\n\t\t\t3. Back to Management Menu" << endl;
        cout << "\n\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> optD;
        if (optD == 1)
        {
            system("cls");
            title();
            objSM.showAllStaff();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            StaffManagement();
        }
        else if (optD == 2)
        {
            system("cls");
            title();
            objSM.deleteAllStaff();
            cout << "\n\n\t\t\tPress Enter Key to go back to the menu..." << endl;
            getch();
            StaffManagement();
        }
        else if (optD == 3)
        {
            system("cls");
            title();
            management();
        }
        else if (optD == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // MEDICINE MENU PAGE

    void MEDICINE()
    {
        system("cls");
        int optm = 0;
        title();
        cout << "\n\n\t\t\t1. Availability of Medicines" << endl;
        cout << "\n\t\t\t2. Buy Medicine" << endl;
        cout << "\n\t\t\t3. Back to Pharmacy Menu" << endl;
        cout << "\n\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> optm;
        if (optm == 1)
        {
            system("cls");
            title();
            objMed.Availability_of_Medicines();
            cout << "\t\t\tPress any key to go back to the menu" << endl;
            getch();
            MEDICINE();
        }
        else if (optm == 2)
        {
            system("cls");
            title();
            objMed.Buy_Medicine();
            cout << "\t\t\t*** Details Added Successfully *** " << endl;
            cout << "\t\t\tPress any key to go back to the menu ..." << endl;
            getch();
            MEDICINE();
        }
        else if (optm == 3)
        {
            system("cls");
            title();
            pharmacy();
        }
        else if (optm == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press any key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // BLOODBANK MENU PAGE

    void BLOODBANK()
    {
        system("cls");
        int optb = 0;
        title();
        cout << "\n\n\t\t\t1. Available Blood Details" << endl;
        cout << "\t\t\t2. Donor and Acceptor Details" << endl;
        cout << "\t\t\t3. Back to Pharmacy Menu" << endl;
        cout << "\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> optb;
        if (optb == 1)
        {
            system("cls");
            title();
            objBB.Available_Blood_Details();
            cout << "\t\t\tPress any key to go back to the menu" << endl;
            getch();
            BLOODBANK();
        }
        else if (optb == 2)
        {
            system("cls");
            title();
            objBB.Donor_and_Acceptor_Details();
            cout << "\t\t\t*** Details Added Successfully *** " << endl;
            cout << "\t\t\tPress any key to go back to the menu ..." << endl;
            getch();
            BLOODBANK();
        }
        else if (optb == 3)
        {
            system("cls");
            title();
            pharmacy();
        }
        else if (optb == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press any key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // EQUIPMENT MENU PAGE

    void EQUIPMENT()
    {
        system("cls");
        int opte = 0;
        title();
        cout << "\n\n\t\t\t1. Available Equipment Details" << endl;
        cout << "\t\t\t2. Buy Equipment" << endl;
        cout << "\t\t\t3. Back to Pharmacy Menu" << endl;
        cout << "\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> opte;
        if (opte == 1)
        {
            system("cls");
            title();
            objEquip.Available_Equipment_Details();
            cout << "\t\t\tPress any key to go back to the menu" << endl;
            getch();
            EQUIPMENT();
        }
        else if (opte == 2)
        {
            system("cls");
            title();
            objEquip.Buy_Equipment();
            cout << "\t\t\t*** Details Added Successfully *** " << endl;
            cout << "\t\t\tPress any key to go back to the menu ..." << endl;
            getch();
            EQUIPMENT();
        }
        else if (opte == 3)
        {
            system("cls");
            title();
            pharmacy();
        }
        else if (opte == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press any key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // OPD MENU PAGE

    void OPD()
    {
        system("cls");
        int opto = 0;
        title();
        cout << "\n\n\t\t\t1. Availability of Doctors" << endl;
        cout << "\t\t\t2. Show OPD Receipt" << endl;
        cout << "\t\t\t3. Back to Finance Menu" << endl;
        cout << "\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> opto;
        if (opto == 1)
        {
            system("cls");
            title();
            objOPD.Availability_of_Doctors();
            cout << "\t\t\tPress any key to go back to the menu" << endl;
            getch();
            OPD();
        }
        else if (opto == 2)
        {
            system("cls");
            title();
            objOPD.Show_OPDReceipt();
            cout << "\t\t\t*** Details Added Successfully *** " << endl;
            cout << "\t\t\tPress any key to go back to the menu ..." << endl;
            getch();
            OPD();
        }
        else if (opto == 3)
        {
            system("cls");
            title();
            finance();
        }
        else if (opto == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press any key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // EMERGENCY MENU PAGE

    void EMERGENCY()
    {
        system("cls");
        int opte = 0;
        title();
        cout << "\n\n\t\t\t1. Doctors Available" << endl;
        cout << "\t\t\t2. Show Emergency Receipt" << endl;
        cout << "\t\t\t3. Back to Finance Menu" << endl;
        cout << "\t\t\t4. Logout " << endl;
        cout << "\n\nSelect any one option (1-4)" << endl;
        cin >> opte;
        if (opte == 1)
        {
            system("cls");
            title();
            objEme.Doctors_Available();
            cout << "\t\t\tPress any key to go back to the menu" << endl;
            getch();
            EMERGENCY();
        }
        else if (opte == 2)
        {
            system("cls");
            title();
            objEme.Show_EmergencyReceipt();
            cout << "\t\t\t*** Details Added Successfully *** " << endl;
            cout << "\t\t\tPress any key to go back to the menu ..." << endl;
            getch();
            EMERGENCY();
        }
        else if (opte == 3)
        {
            system("cls");
            title();
            finance();
        }
        else if (opte == 4)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press any key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    // LABORATORY MENU PAGE

    void LABORATORY()
    {
        system("cls");
        int optl = 0;
        title();
        cout << "\t\t\t1. Add Reports" << endl;
        cout << "\t\t\t2. Delete Report" << endl;
        cout << "\t\t\t3. Show Lab Receipt" << endl;
        cout << "\t\t\t4. Back to Finance Menu" << endl;
        cout << "\t\t\t5. Logout " << endl;
        cout << "\n\nSelect any one option (1-5)" << endl;
        cin >> optl;

        if (optl == 1)
        {
            system("cls");
            title();
            objLab.Add_Reports();
            cout << "\t\t\t*** Details Added Successfully *** " << endl;
            cout << "\t\t\tPress any key to go back to the menu ..." << endl;
            getch();
            LABORATORY();
        }
        else if (optl == 2)
        {
            system("cls");
            title();
            objLab.Delete_Report();
            cout << "\t\t\tPress any key to go back to the menu ..." << endl;
            getch();
            LABORATORY();
        }
        else if (optl == 3)
        {
            system("cls");
            title();
            objLab.Show_LabReceipt();
            cout << "\t\t\tPress any key to go back to the menu" << endl;
            getch();
            LABORATORY();
        }
        else if (optl == 4)
        {
            system("cls");
            title();
            finance();
        }
        else if (optl == 5)
        {
            system("cls");
            title();
            cout << "\n\n\t\t\tLogout Successfully !! Press any key to continue..";
            getch();
            cin.ignore();
            welcomePage();
        }
    }

    //// details Menu Page ////

    void details()
    {
        title();
        int opt = 0;
        cout << "\t\t\t\t1. Doctors Details\n"
             << endl;
        cout << "\t\t\t\t2. Patient Details\n"
             << endl;
        cout << "\t\t\t\t3. Sideworkers Details\n"
             << endl;
        cout << "\t\t\t\t4. Back to Main Menu\n"
             << endl;
        cout << "\t\t\t\t5. Logout\n"
             << endl;
        cout << "\n\n\t\t\tSelect any option from 1-5" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            DoctorDetail();
        case 2:
            PatientDetail();
        case 3:
            SideworkerDetail();
        case 4:
            menuPage();
        case 5:
            cout << "\t\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            welcomePage();
        }
    }

    /// Feedback Menu Page ///

    void feedbacks()
    {
        title();
        int opt = 0;
        cout << "\n\t\t\t\t1. Hospital Feedback" << endl;
        cout << "\n\t\t\t\t2. Doctors Feedback" << endl;
        cout << "\n\t\t\t\t3. Sideworkers Feedback" << endl;
        cout << "\n\t\t\t\t4. Back to Main Menu" << endl;
        cout << "\n\t\t\t\t5. Logout" << endl;
        cout << "\n\n\t\t\tSelect any option from 1-5" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            HospitalFeedback();
        case 2:
            DoctorsFeedback();
        case 3:
            SideworkersFeedback();
        case 4:
            menuPage();
        case 5:
            cout << "\t\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            welcomePage();
        }
    }

    /// Finance Menu Page ///

    void finance()
    {
        title();
        int opt = 0;
        cout << "\t\t\t\t1. OPD" << endl;
        cout << "\n\t\t\t\t2. Emergency" << endl;
        cout << "\n\t\t\t\t3. Laboratory" << endl;
        cout << "\n\t\t\t\t4. Back to Main Menu" << endl;
        cout << "\n\t\t\t\t5. Logout" << endl;
        cout << "\n\n\t\t\tSelect any option from 1-5" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            OPD();
        case 2:
            EMERGENCY();
        case 3:
            LABORATORY();
        case 4:
            menuPage();
        case 5:
            cout << "\t\t\t\tLogout Successfully !! Press any key to continue..";
            getch();
            welcomePage();
        }
    }

    void pharmacy()
    {
        title();
        int opt = 0;
        cout << "\t\t\t\t1. Medicine" << endl;
        cout << "\t\t\t\t2. BloodBank" << endl;
        cout << "\t\t\t\t3. Equipment" << endl;
        cout << "\t\t\t\t4. Back to Main Menu" << endl;
        cout << "\t\t\t\t5. Logout" << endl;
        cout << "\n\n\t\t\tSelect any option from 1-5" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            MEDICINE();
        case 2:
            BLOODBANK();
        case 3:
            EQUIPMENT();
        case 4:
            menuPage();
        case 5:
            cout << "\t\t\t\tLogout Successfully !! Press any key to continue..";
            getch();
            welcomePage();
        }
    }

    /// Management Menu Page ///

    void management()
    {
        title();
        int opt = 0;
        cout << "\n\t\t\t\t1. Room Management " << endl;
        cout << "\n\t\t\t\t2. Ambulance Management" << endl;
        cout << "\n\t\t\t\t3. Staff Management" << endl;
        cout << "\n\t\t\t\t4. Back to Main Menu" << endl;
        cout << "\n\t\t\t\t5. Logout" << endl;
        cout << "\n\n\t\t\tSelect any option from 1-5" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            RoomManagement();
        case 2:
            AmbulanceManagement();
        case 3:
            StaffManagement();
        case 4:
            menuPage();
        case 5:
            cout << "\t\t\t\tLogout Successfully !! Press Enter Key to continue..";
            getch();
            welcomePage();
        }
    }

    //Main Menu Page

    void menuPage()
    {
        int opt = 0;
        title();
        cout << "\t\t\t\t1. D E T A I L S \n"
             << endl;
        cout << "\t\t\t\t2. M A N A G E M E N T \n"
             << endl;
        cout << "\t\t\t\t3. P H A R M A C Y \n"
             << endl;
        cout << "\t\t\t\t4. F I N A N C E \n"
             << endl;
        cout << "\t\t\t\t5. F E E D B A C K S \n"
             << endl;
        cout << "\t\t\t\t6. L O G O U T \n"
             << endl;
        cout << "\n\nSelect any option (1-6) ..." << endl;
        // cin.ignore();
        cin >> opt;
        switch (opt)
        {
        case 1:
            details();
        case 2:
            management();
        case 3:
            pharmacy();
        case 4:
            finance();
        case 5:
            feedbacks();
        case 6:
            cout << "\n\n\t\t\tLogout Successfully !!!! Press Enter Key to continue..";
            getch();
            welcomePage();
        }
    }
};

//MAIN BODY
int main()
{
    system("cls");
    HOSPITAL_MANAGEMENT_SYSTEM obj;
    obj.welcomePage();
    return 0;
}