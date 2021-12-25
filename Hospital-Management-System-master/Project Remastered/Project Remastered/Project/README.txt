//Intro

Hospital, an institution that is built, staffed, and equipped for the diagnosis of disease; for the treatment, both medical and surgical, of the sick and the injured; and for their housing during this process. The modern hospital also often serves as a centre for investigation and for teaching.


//USERNAME AND PASSWORD

//This is saved in admin.txt

username : admin
password : 123


// Group Members

1. Nashra Ghaffar (CT-032)
2. Hamza Ahmed Khan (CT-035)
3. M. Abdul Rafay (CT-012)
4. Minahil Tariq (CT-026)

//NASHRA'S Work 

Assalamoalaikum !! I have deisigned three main classes with an abstract class..
Abstract class name = Details 
1. Doctor Details
2. Patient Details
3. SideWorkers Details

And I have tried to use the concepts of oop which include Constructors, Inheritance and Composition and Pure Virtual Function. I have also used the concept of filing as much as I can. And I also tried to make the UI a little attractive , for which I have made another class named HOSPITAL_MANAGEMENT_SYSTEM , which includes the functions like welcomePage , menuPage etc. 

//Details class
In this class I have declared 3 pure virtual functions which include:
	virtual void getDetails() = 0;
  	virtual void showDetails() = 0;
  	virtual void removeDetail() = 0;

// Doctor Details Class:
 In this class, I have made 4 functions that are :
	void commonInputs();
    	void getDetails();
   	void showDetails();
    	void removeDetail();


// Patient Details Class:
 This class is inherited from the Doctor Details Class and , I have made 3 functions that are :
    	void getDetails();
   	void showDetails();
    	void removeDetail();
	void commonInputs(); (Inherited from the Doctor Details)


// SideWorker Details Class:
 In this class, I have made 3 functions that are: 
    	void getDetails();
   	void showDetails();
    	void removeDetail();

I didn't inherit commonInputs function here because there was no need of it. We have to take very few values as input so I directly take them.

NOTE: I have taken all the data members as string because whenever I was declaring them with different data types, they were causing problem while taking input , so as I wasn't supposed to perform any calculation with the values so I took them as "string".

I have wriiten all the details in separate files. And yes I tried to add comments in the whole project so that it would become easier to understand. And yes that was it for my part. Bye :)

=======================================================================================================================================================================
