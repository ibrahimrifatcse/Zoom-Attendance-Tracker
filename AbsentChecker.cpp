#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Open files for reading
    ifstream all_ids_file("EcoAll.txt");
    ifstream garbage_ids_file("Echogarbage.txt");

    // Check if files opened successfully
    if (!all_ids_file.is_open())
    {
        cout << "Error: Unable to open all_ids.txt file." << endl;
        return 1;
    }
    if (!garbage_ids_file.is_open())
    {
        cout << "Error: Unable to open garbage_ids.txt file." << endl;
        return 1;
    }

    // Read all IDs from all_ids.txt into a vector
    vector<string> all_ids;
    string id;
    while (getline(all_ids_file, id))
    {
        all_ids.push_back(id);
    }
    all_ids_file.close();

    // Read all IDs from garbage_ids.txt into a vector
    vector<string> garbage_ids;
    while (garbage_ids_file >> id)
    {
        // Check if the ID is 9 digits long
        if (id.length() == 9 && all_of(id.begin(), id.end(), ::isdigit))
        {
            garbage_ids.push_back(id);
        }
    }
    garbage_ids_file.close();

    // Find the missing IDs
    vector<string> missing_ids;
    for (string student_id : all_ids)
    {
        if (find(garbage_ids.begin(), garbage_ids.end(), student_id) == garbage_ids.end())
        {
            missing_ids.push_back(student_id);
        }
    }
int a =0;
    // Print the missing IDs
    cout << "Absent students:" << endl;
    for (string student_id : missing_ids)
    {
        cout <<++a<<" "<< student_id << endl;
    }

    return 0;
}
