#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    stringstream inputElement;
    // the number of testcases (first number of the first row in the input)
    int caseNo = 0;
    // pointer to the number of inputs in each TC
    int *inputs;
    
    // string to put all the line
    string allString;
    // get the name of the file
    string name;
    // get the extension of the file 
    string extension;
    // get the size of the file in b
    string bSize;

    

    // the size of the file in each category
    int musicLen    = 0;
    int imagesLen   = 0;
    int moviesLen   = 0;
    int otherLen    = 0;
    
    // pointers to save the length of the files depend on the category in each test case 
    int *musicLens ;
    int *imagesLens; 
    int *moviesLens; 
    int *otherLens ; 

    int fileSize = 0;
    std::size_t found;
    // flag to know that it is the first line of the input
    int firstInput = 1;
    int i = 0;
    
    while(true)
    {
      
        /* first input in the line, that represent the number of the test cases */
        if(firstInput == 1)
        {
          // change the flag to not enter here again
            firstInput = 0;
            // take no. of testcases from the user
            cin>>caseNo;
            //alocate memory 
            inputs = new int[caseNo];
            musicLens = new int[caseNo];
            imagesLens= new int[caseNo]; 
            moviesLens= new int[caseNo]; 
            otherLens = new int[caseNo];
            // set index =0 
            i=0; 
        }
        else
        {
            // add the data which intered from the user
            cin>>inputs[i];
            // increse the index
            i++;
        }
        if(cin.peek() =='\n')
        {
            break;
        }
    }
    // flush the buffer
    cin.ignore();
    
    for(int i=0;i<caseNo;i++)
    {
        // initiate all lengths with 0
        musicLen  = 0;
        imagesLen = 0;
        moviesLen = 0;
        otherLen  = 0;

        for(int j=0;j<(inputs[i]);j++)
        {
            // get a line of input from user and put it in allString
            getline(cin, allString); 

            stringstream inputElement(allString);
            // store all chars. till the space in var. name(name of the file and the extension)
            inputElement>>name; 
            found = name.find_last_of('.');
            extension = name.substr(found+1);
            
            // get the second part from allString to get the size from
            inputElement>>name;
            int size = name.length() - 1;
            bSize = "";
            
            for(int i=0;i<size;i++)
            {
                bSize += name[i];
            }
            //  stio() use to change the type of the fileSize from string to int
            fileSize = stoi(bSize); 
            // checking the file is music, image, movie or others from the extension
            
            if(extension == "mp3" ||extension == "acc"||extension == "flac")
            {
                musicLen += fileSize;
            }
            else if(extension == "jpg" || extension == "bmp"||extension == "gif")
            {
                imagesLen += fileSize;
            }
            else if(extension == "mp4" ||extension == "avi"||extension == "mkv")
            {
                moviesLen += fileSize;
            }
            else
            {
                otherLen += fileSize;
            }
        }
        
        // save the prev. file in its category buffer
        musicLens[i] = musicLen; 
        imagesLens[i]= imagesLen;
        moviesLens[i]= moviesLen;
        otherLens[i] = otherLen;
    }
    
    // print the output of each TC in one line
    for(int i=0;i<caseNo;i++)
    {
        std::cout<<"music "<<musicLens[i];
        std::cout<<"b images "<<imagesLens[i];
        std::cout<<"b movies "<<moviesLens[i];
        std::cout<<"b other "<<otherLens[i]<<"b"<<std::endl;
    }
    return 0;
}