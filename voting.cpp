#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int main()
{
    int NumCan, NumStu, Vote;
    int VoteFor[10] = {0}; // Initialize all elements to 0
    char CanName[10][1000], id[100][1000], ch;
    char pass[50];

    cout << endl
         << "                     Online Voting System / CR Election System                   " << endl;
    cout << "                     _________________________________________                   " << endl;
    cout << endl
         << "                        :::::::::: ADMIN PANEL ::::::::::" << endl;
    cout << endl
         << "=================================================================================" << endl;
    cout << endl
         << endl
         << "    Number of Candidates: ";
    cin >> NumCan;

    if (NumCan > 1)
    {
        for (int i = 1; i <= NumCan; i++)
        {
            cout << "    Candidate-" << i << " Name: ";
            cin >> CanName[i];
        }

        cout << "    Number of Students: ";
        cin >> NumStu;
        cout << endl
             << "  Thank You Admin! We are going to start our election with " << NumStu << " Students and " << NumCan << " Candidates." << endl;
        cout << endl
             << endl
             << "=================================================================================" << endl;

        cout << endl
             << "                            Enter The Password: ";
        cin >> pass;
        while (strcmp(pass, "mypass") != 0)
        {
            cout << endl
                 << "                            Wrong Password! Try Again." << endl;
            cout << "                       Enter The Correct Password: ";
            cin >> pass;
            cout << endl;
        }
        system("CLS");

        ofstream voteDetailsFile("VoteDetails.txt"); // Open the file to append the details
        if (!voteDetailsFile.is_open())
        {
            cout << "Unable to open file to write vote details." << endl;
            return 1;
        }

        for (int i = 1; i <= NumStu; i++)
        {
            cout << endl
                 << "                     Online Voting System / CR Election System                   " << endl;
            cout << "                     _________________________________________                   " << endl;
            cout << endl
                 << "                        :::::::::: VOTING PANEL ::::::::::" << endl;
            cout << endl
                 << "                                   Student - " << i << endl;
            cout << endl
                 << "=================================================================================" << endl;
            cout << endl;

            FILE *filepointer;
            char datatoberead[50];
            filepointer = fopen("ID.txt", "r");
            char inputid[50];
            cout << endl
                 << "                             Enter Your ID: ";
            cin >> inputid;
            strcat(inputid, "\n");

            bool id_found = false;
            int c = 0;
            while (fgets(datatoberead, 50, filepointer) != NULL)
            {
                c++;
                if (strcmp(inputid, datatoberead) == 0)
                {
                    cout << "                                    Data found!" << endl;
                    id_found = true;

                    FILE *filepointer2;
                    char datatoberead2[50];
                    filepointer2 = fopen("Name.txt", "r");
                    int d = 0;
                    while (fgets(datatoberead2, 50, filepointer2) != NULL)
                    {
                        d++;
                        if (c == d)
                        {
                            cout << endl
                                 << "    Name: " << datatoberead2;
                            cout << "    ID: " << inputid << endl;
                        }
                    }
                    fclose(filepointer2);
                    break;
                }
            }
            fclose(filepointer);

            if (!id_found)
            {
                cout << "Sorry, ID Not Found! or you typed wrong ID. Please Try Again." << endl;
                i--; // Decrement student count to retry
                continue;
            }

            cout << endl
                 << "                  ===========================================" << endl;
            cout << endl;
            for (int j = 1; j <= NumCan; j++)
            {
                cout << "                              Press " << j << " For " << CanName[j] << endl;
            }
            cout << endl
                 << "                  ===========================================" << endl;
            cout << "    Now, Please Put Your Vote: ";
            ch = getch();
            Vote = ch - '0';
            cout << "(Hidden)" << endl;

            // Register the vote
            VoteFor[Vote]++;
            cout << endl
                 << "                  Thanks " << id[i] << " For Your Vote. (Press Enter for Next)" << endl;
            getch();
            system("CLS");

            // Append vote details to file
            voteDetailsFile << "Student ID: " << inputid << endl;
            voteDetailsFile << "Vote: " << CanName[Vote] << endl
                            << endl;
        }

        voteDetailsFile.close(); // Close the file after writing all the details

        system("CLS");
        cout << endl
             << "                     Online Voting System / CR Election System                   " << endl;
        cout << "                     _________________________________________                   " << endl;
        cout << endl
             << "                        :::::::::: RESULT PANEL ::::::::::" << endl;
        cout << endl
             << "=================================================================================" << endl;
        cout << endl
             << endl
             << "                            Enter The Password: ";
        cin >> pass;
        while (strcmp(pass, "mypass") != 0)
        {
            cout << endl
                 << "                            Wrong Password! Try Again." << endl;
            cout << "                       Enter The Correct Password: ";
            cin >> pass;
            cout << endl;
        }
        cout << endl
             << "                  ===========================================" << endl;
        for (int j = 1; j <= NumCan; j++)
        {
            cout << "                              " << CanName[j] << " Got " << VoteFor[j] << " Vote(s)." << endl;
        }
        cout << endl
             << "                  ===========================================" << endl;

        // Find the candidate(s) with the maximum votes
        int maxVotes = 0;
        for (int j = 1; j <= NumCan; j++)
        {
            if (VoteFor[j] > maxVotes)
            {
                maxVotes = VoteFor[j];
            }
        }

        for (int j = 1; j <= NumCan; j++)
        {
            if (VoteFor[j] == maxVotes)
            {
                cout << endl
                     << "           Congratulations " << CanName[j] << ". You are elected as our new CR." << endl;
                break;
            }
        }
        cout << endl
             << "=================================================================================" << endl;
    }
    else
    {
        cout << endl
             << "Sorry! Number of Candidates must be more than one person." << endl;
    }

    getch();
    return 0;
}
