#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <fstream.h>

#ifndef SimpleFArrayH
#define SimpleFArrayH
#include <stdlib.h>
#include <string.h>

// by: Imam Cholissodin | 22 Desember 2007
// Big Thanks to All, especially to my friend Math'03 a.n. Adul atau Haris :D


typedef float Real;

class SimpleFArray {
public:
    SimpleFArray(int n);                               // Create array of n elements
    SimpleFArray();                                    // Create array of 0 elements
    SimpleFArray(const SimpleFArray&);                 // Copy array
    ~SimpleFArray();                                   // Destroy array
    Real& operator[](int i);                          // Subscripting
    const Real& operator[](int i) const;              // Subscripting
    int numElts() const;                               // Number of elements
    SimpleFArray& operator=(const SimpleFArray&);      // Array assignment
    SimpleFArray& operator=(const&);                   // Scalar assignment
    void setSize(int n);                               // Change size
private:
    int num_elts;                                      // Number of elements
    Real* ptr_to_data;                                // Pointer to built-in array of elements
    void copy(const SimpleFArray& a);                  // Copy in elements of a

};

SimpleFArray::SimpleFArray(int n) {
    num_elts = n;
    ptr_to_data = new Real[n];
}

SimpleFArray::SimpleFArray() {
    num_elts = 0;
    ptr_to_data = 0;
}

SimpleFArray::SimpleFArray(const SimpleFArray& a) {
    num_elts = a.num_elts;
    ptr_to_data = new Real[num_elts];
    copy(a); // Copy a's elements
}

void SimpleFArray::copy(const SimpleFArray& a) {
    // Copy a's elements into the elements of *this
    Real* p = ptr_to_data + num_elts;
    Real* q = a.ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = *--q;
}

SimpleFArray::~SimpleFArray() {
    delete [] ptr_to_data;
}

Real& SimpleFArray::operator[](int i) {
  return ptr_to_data[i];
}

const Real& SimpleFArray::operator[](int i) const {
    return ptr_to_data[i];
}

int SimpleFArray::numElts() const {
    return num_elts;
}

SimpleFArray& SimpleFArray::operator=(const SimpleFArray& rhs) {
    if (ptr_to_data != rhs.ptr_to_data ) {
        setSize( rhs.num_elts );
        copy(rhs);
    }
    return *this;
}

void SimpleFArray::setSize(int n) {
    if (n != num_elts) {
        delete [] ptr_to_data;    // Delete old elements,
        num_elts = n;             // set new count,
        ptr_to_data = new Real[n];   // and allocate new elements

    }
}

SimpleFArray& SimpleFArray::operator=(const int& rhs) {
    Real* p = ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = rhs;
    return *this;
}

#endif
#ifndef SimpleIArrayH
#define SimpleIArrayH

class SimpleIArray {
public:
    SimpleIArray(int n);                               // Create array of n elements
    SimpleIArray();                                    // Create array of 0 elements
    SimpleIArray(const SimpleIArray&);                 // Copy array
    ~SimpleIArray();                                   // Destroy array
    int& operator[](int i);                            // Subscripting
    const int& operator[](int i) const;                // Subscripting
    int numElts() const;                               // Number of elements
    SimpleIArray& operator=(const SimpleIArray&);      // Array assignment
    SimpleIArray& operator=(const&);                   // Scalar assignment
    inline void setSize(int n);                        // Change size
//    char* text();           //digunakan for display semua elemennya
private:
//    char* DataText;
    int num_elts;                                      // Number of elements
    int* ptr_to_data;                                  // Pointer to built-in array of elements
    void copy(const SimpleIArray& a);                  // Copy in elements of a

};

/*
char* SimpleIArray::text(){
    DataText = new char[num_elts*(25)];
    int i;
    char s[24];
    strcpy(DataText,"");
    for (i=0;i<num_elts;i++){
      itoa(ptr_to_data[i],s,10);
    	strcat(DataText,s);
      strcat(DataText," ");
      }
    return DataText;
}
*/

SimpleIArray::SimpleIArray(int n) {
    num_elts = n;
    ptr_to_data = new int[n];
}

SimpleIArray::SimpleIArray() {
    num_elts = 0;
    ptr_to_data = 0;
}

SimpleIArray::SimpleIArray(const SimpleIArray& a) {
    num_elts = a.num_elts;
    ptr_to_data = new int[num_elts];
    copy(a); // Copy a's elements
}

void SimpleIArray::copy(const SimpleIArray& a) {
    // Copy a's elements into the elements of *this
    int* p = ptr_to_data + num_elts;
    int* q = a.ptr_to_data + num_elts;
        while (p > ptr_to_data) *--p = *--q;
}

SimpleIArray::~SimpleIArray() {
    delete [] ptr_to_data;
    }

int& SimpleIArray::operator[](int i) {
   return ptr_to_data[i];
}

const int& SimpleIArray::operator[](int i) const {
    return ptr_to_data[i];
}

int SimpleIArray::numElts() const {
    return num_elts;
}

SimpleIArray& SimpleIArray::operator=(const SimpleIArray& rhs) {
    if (ptr_to_data != rhs.ptr_to_data ) {
        setSize( rhs.num_elts );
        copy(rhs);
    }
    return *this;
}

void SimpleIArray::setSize(int n) {
     if (n != num_elts) {
        delete [] ptr_to_data;    // Delete old elements,
        num_elts = n;             // set new count,
        ptr_to_data = new int[n];   // and allocate new elements
    }
}

SimpleIArray& SimpleIArray::operator=(const int& rhs) {
    int* p = ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = rhs;
    return *this;
}

#endif
#ifndef SimpleArrayH
#define SimpleArrayH

template<class T> class SimpleArray;

template<class T>
class SimpleArray {
public:
    inline SimpleArray(int n);                                 // Create array of n elements
    inline SimpleArray();                                      // Create array of 0 elements
    inline SimpleArray(const SimpleArray<T>&);                 // Copy array
    inline ~SimpleArray();                                     // Destroy array
    inline T& operator[](int i);                               // Subscripting
    inline const T& operator[](int i) const;                   // Subscripting
    inline int numElts() const;                                // Number of elements
    SimpleArray<T>& operator=(const SimpleArray<T>&);          // Array assignment
    SimpleArray<T>& operator=(const T&);                       // Scalar assignment 
    inline void setSize(int n);                                // Change size
private:
    int num_elts;                                              // Number of elements
    T* ptr_to_data;                                            // Pointer to built-in array of elements
    void copy(const SimpleArray<T>& a);                        // Copy in elements of a

};



template<class T>
inline SimpleArray<T>::SimpleArray(int n) {
    num_elts = n;
    ptr_to_data = new T[n];
}

template<class T>
inline SimpleArray<T>::SimpleArray() {
    num_elts = 0;
    ptr_to_data = 0;
}

template<class T>
inline SimpleArray<T>::SimpleArray(const SimpleArray<T>& a) {
    num_elts = a.num_elts;
    ptr_to_data = new T[num_elts];
    copy(a); // Copy a's elements
}

template<class T>
void SimpleArray<T>::copy(const SimpleArray<T>& a) {
    // Copy a's elements into the elements of *this
    T* p = ptr_to_data + num_elts;
    T* q = a.ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = *--q;
}

template<class T>
inline SimpleArray<T>::~SimpleArray() {
    delete [] ptr_to_data;
//    cout<<"SimpleArray dihapus"<<endl;
//    getch();
}

template<class T>
inline T& SimpleArray<T>::operator[](int i) {
    return ptr_to_data[i];
}

template<class T>
inline const T& SimpleArray<T>::operator[](int i) const {
    return ptr_to_data[i];
}

template<class T>
inline int SimpleArray<T>::numElts() const {
    return num_elts;
}

template<class T>
SimpleArray<T>& SimpleArray<T>::operator=(const SimpleArray<T>& rhs) {
    if ( ptr_to_data != rhs.ptr_to_data ) {
        setSize( rhs.num_elts );
        copy(rhs);
    }
    return *this;
}

template<class T>
inline void SimpleArray<T>::setSize(int n) {
    if (n != num_elts) {

        delete [] ptr_to_data;    // Delete old elements,
        num_elts = n;             // set new count,
        ptr_to_data = new T[n];   // and allocate new elements

    }
}

template<class T>
SimpleArray<T>& SimpleArray<T>::operator=(const T& rhs) {
    T* p = ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = rhs;
    return *this;
}

#endif

class class_TSP                              //class TSP
{
	public:
   ~class_TSP();
   void setsize(int);                         //function to set length array
   int sum_individual();
   void read_data();									//function read data *.txt
   SimpleIArray generate_individual();
   void generate_population();                 //function generate population
   float value_z(SimpleIArray);
   void show_evaluation();
   void localsearch(int,float , int );
   void fitness(int);
   void selection_crossover(float,int);
   void selection_mutation(float ,int );
   void crossover_pmx(int);
   void mutation_bim(int);
   void cluster_offspring_crossover_mutation(int);
   void localsearch2(int,float , int );
   void show_population_new(int ); 

   private:
	int sum_city;									
	SimpleArray<SimpleFArray> data_distance;		//data_distance city
   SimpleArray<SimpleIArray> matrix_population;   //matrix population
   SimpleArray<SimpleIArray> gen_initial;   //patching result local search initial
   SimpleFArray result_evaluation;
   SimpleIArray result_fitness;
   SimpleIArray result_mother_crossover;
   SimpleIArray result_mother_mutation;
   SimpleArray<SimpleIArray> temp_string; //to patching offspring crossover
   SimpleArray<SimpleIArray> temp_string2; //to patching offspring mutation
   SimpleArray<SimpleIArray> result_offspring; //to patching offspring crossover + mutation
   SimpleArray<SimpleIArray> gen_initial2;  //patching result of localsearch offspring
   SimpleArray<SimpleIArray> result_population_new;
   int sum_mother_crossover,sum_mother_mutation;

};

void main()
{
	randomize();
   class_TSP program;  //object "program"
   int pop_size,max_gen,p;
   float epsilon,pc,pm;
   cout<<"Input population (10)= "; //recommended population 10
 	cin>>pop_size;
   do{
   cout<<"Input epsilon (0.8) = "; //recommended epsilon = 0.8
 	cin>>epsilon;
   }while(epsilon<=0 || epsilon>=1);

   cout<<"Input P (4)=  "; //recommended P=4
 	cin>>p;

   do{
   cout<<"Input Pc (0.5)= "; //recommended Pc=0.5
 	cin>>pc;
   }while(pc<=0 || pc>=1);

   do{
   cout<<"Input Pm (0.01)= "; //recommended Pm=0.01
 	cin>>pm;
   }while(pm<=0 || pm>=1);
   
   cout<<"Input max gen (100)= "; //recommended Pm=100..1000
 	cin>>max_gen;

   program.setsize(pop_size);
   program.read_data();                  
   program.generate_population();          
   program.show_evaluation();
   cout<<"\nPlease wait..";
   for(int i=1;i<=max_gen;i++){
   program.localsearch(pop_size,epsilon,p); 
   cout<<".";
   program.fitness(pop_size);
   cout<<".";
   program.selection_crossover(pc,pop_size);
   cout<<".";
   program.selection_mutation(pm,pop_size);
   cout<<".";
   program.crossover_pmx(pop_size);
   cout<<".";
   program.mutation_bim(pop_size);
   cout<<".";
   program.cluster_offspring_crossover_mutation(pop_size);
   cout<<".";

   //second localssearch after cluster_offspring_crossover_mutation
   program.localsearch2(pop_size,epsilon,p);
   cout<<".";
   program.show_population_new(pop_size);
   //cout<<"._";
   cout<<"\n=========================================== Looping gen "<<i<<" from "<<max_gen<<"\n";
   cout<<"\nPlease wait..";
   //getch();
   }
   getch();
   abort();
}

class_TSP::~class_TSP(){}

void class_TSP::setsize(int pop)  //determine size of matrix population
{
	matrix_population.setSize(pop);
}

int class_TSP::sum_individual()  //ukuran matrix population initial
{
	return matrix_population.numElts();
}

void class_TSP::read_data()
{
  ifstream open_file;  								//open file
  open_file.open("data_100_city.txt");
  //open_file.open("data_10_city.txt");
  open_file>>sum_city;
  cout<<"sum_city : "<<sum_city<<endl;
  cout<<endl;
  data_distance.setSize(sum_city);
  float *databar;
  int sum_data = sum_city*sum_city;
  databar = new float[sum_data];
  int index=0;
  while(!open_file.eof())
  {
  		open_file>>databar[index];
   	index++;
  }

  open_file.close();
  SimpleFArray temp;
  temp.setSize(sum_data);
  int count=0;
  for(int i=0;i<sum_city;i++)
  {
		for(int j=0;j<sum_city;j++)
  		{
			temp[j]=databar[count];
			count++;
  		}
		data_distance[i]=temp;
  }

  //display data

  cout<<"Data distance city "<<endl<<endl;
  for(int i=0;i<sum_city;i++)
  {
   	for(int j=0;j<sum_city;j++)
  		{
			cout<<data_distance[i][j]<<"\t";
  		}
      cout<<endl;
  }
  cout<<endl;

}

SimpleIArray class_TSP::generate_individual()
{
	SimpleIArray cromosom;
   cromosom.setSize(sum_city);

   SimpleIArray temp;
   temp.setSize(sum_city);

   for(int i=0;i<sum_city;i++)
   {
   	temp[i]=i;
   }

   for(int i=0;i<sum_city;i++)
   {
    	int position=random(sum_city-i);
      cromosom[i]=temp[position];
      for(int j=position;j<sum_city-1;j++)
      {
      	temp[j]=temp[j+1];
      }
   }

   return cromosom;                          
}

void class_TSP::generate_population()
{        
	int pop_size=sum_individual();
	for(int i=0;i<pop_size;i++)
   {
   	matrix_population[i]=generate_individual();
   }

   for(int i=0;i<pop_size;i++)
   {
   	cout<<"Individual to "<<i<<" : ";
   	for(int j=0;j<sum_city;j++)
      {
      	cout<<matrix_population[i][j]<<"  ";
      }
      cout<<endl;
   }
}

float class_TSP::value_z(SimpleIArray vector)
{
	float result=0.0;
	SimpleArray<SimpleIArray> matrix_biner(sum_city);
	SimpleIArray temp(sum_city);

	for(int i=0;i<sum_city;i++) temp[i]=0;

	for(int i=0;i<sum_city;i++) matrix_biner[i]=temp;

	for(int i=0;i<sum_city;i++)
	{
		matrix_biner[vector[i]][vector[i+1]]=1;
	}

   SimpleArray<SimpleFArray> result_multiplication(sum_city);
   SimpleFArray temp1(sum_city);

   for(int i=0;i<sum_city;i++)
   {
   	temp1[i]=0.0;
   }
   for(int i=0;i<sum_city;i++)
   {
   	result_multiplication[i]=temp1;
   }

	for(int i=0;i<sum_city;i++)
	{
   	float temp_result=0.0;
		for(int j=0;j<sum_city;j++)
  		{
         result_multiplication[i][j]=data_distance[i][j]*matrix_biner[i][j];
         temp_result=temp_result+result_multiplication[i][j];
  		}
      temp1[i]=temp1[i]+temp_result;
	}

   for(int i=0;i<sum_city;i++) result=result+temp1[i];

   result=result+data_distance[vector[sum_city-1]][vector[0]];
	return result;
}

void class_TSP::show_evaluation()
{
   cout<<"------------------------------------------------------------"<<endl;
	int pop_size=sum_individual();
   result_evaluation.setSize(pop_size);
   for(int i=0;i<pop_size;i++)
   {
   	result_evaluation[i]=value_z(matrix_population[i]);
   }

   for(int i=0;i<pop_size;i++)
   {
   	cout<<"value z individual to "<<i<<":"<<" "<<result_evaluation[i]<<endl;
   }
   cout<<"------------------------------------------------------------"<<endl;

}

void class_TSP::localsearch(int pop_size, float epsilon, int p)
{
ofstream save_file("output_localsearch_initial.txt");
result_evaluation.setSize(pop_size);
gen_initial.setSize(pop_size);
int k1,k2; 					// index to exchange gen
int temp1,t,temp_evaluation;
float e_random;
for(int i=0;i<pop_size;i++)
   {
   	//cout<<"\n=====================================\n";
   	//cout<<"Individual to "<<i<<" : ";
      save_file<<"\n=====================================\n";
      save_file<<"Individual to "<<i<<" : ";
   	for(int j=0;j<sum_city;j++)
      {
      	gen_initial[i]=matrix_population[i];
      	//cout<<matrix_population[i][j]<<"  ";
         save_file<<matrix_population[i][j]<<"  ";
      }
      //cout<<endl;
      save_file<<endl;

      //find result evaluation gen initial
      result_evaluation[i]=value_z(matrix_population[i]);
      temp_evaluation=result_evaluation[i];
      //cout<<"\nresult_evaluation initial = "<<result_evaluation[i]<<"\n";
      save_file<<"\nresult_evaluation initial = "<<result_evaluation[i]<<"\n";

      t=0;
      do{
      //cout<<"\n> exchange gen t ="<<t<<"\n";
      //cout<<" Individual to "<<i<<"  : ";
      save_file<<"\n> exchange gen t ="<<t<<"\n";
      save_file<<" Individual to "<<i<<"  : ";
         do{
         	k1=random(sum_city);
           }
         while(k1==0);
         k2= k1<(sum_city-1) ? k2=k1+1 : k2=k1-1;   	// if k2=k1<(sum_city-1) else k2=k1+1 or k2=k1-1

         //exchange position gen
         temp1=matrix_population[i][k1];
         matrix_population[i][k1]=matrix_population[i][k2];
         matrix_population[i][k2]=temp1;
         for(int j=0;j<sum_city;j++)
         {
      		//gen_initial[i][j]=matrix_population[i][j];
      		//cout<<matrix_population[i][j]<<"  ";
         	save_file<<matrix_population[i][j]<<"  ";
      	}

         //find result evaluation gen initial after exchange
         result_evaluation[i]=value_z(matrix_population[i]);
         //cout<<"\n result_evaluation stlh di exchange = "<<result_evaluation[i]<<"\n";
         save_file<<"\n result_evaluation stlh di exchange = "<<result_evaluation[i]<<"\n";

         //condition for consideration result_evaluation initial with after exchange
         if(result_evaluation[i]<temp_evaluation)
         {
         	result_evaluation[i]=value_z(matrix_population[i]);
      		temp_evaluation=result_evaluation[i];
            //cout<<"\n result_evaluation initial = "<<result_evaluation[i]<<"\n";
            save_file<<"\n result_evaluation initial = "<<result_evaluation[i]<<"\n";
         	t=0;
            //cout<<" Individual new to "<<i<<"  : ";
            save_file<<" Individual new to "<<i<<"  : ";
            // cromosom initial = cromosom last
            for(int j=0;j<sum_city;j++)
            	{
               	//matrix_population[i]='\0';
      				gen_initial[i]=matrix_population[i];
      				//cout<<matrix_population[i][j]<<"  ";
               	save_file<<matrix_population[i][j]<<"  ";
               	////cout<<endl;
      			}
         }
         else if(result_evaluation[i]==temp_evaluation)
         {
           	e_random=random(1000)/1000.0;
           	//cout<<"\n e_random ="<<e_random<<"\n";
            save_file<<"\n e_random ="<<e_random<<"\n";
           	if(e_random<=epsilon)
            {
            	result_evaluation[i]=value_z(matrix_population[i]);
      			temp_evaluation=result_evaluation[i];
               //cout<<"\n result_evaluation initial = "<<result_evaluation[i]<<"\n";
               save_file<<"\n result_evaluation initial = "<<result_evaluation[i]<<"\n";
           		t=0;
               //cout<<" Individual new to "<<i<<"  : ";
               save_file<<" Individual new to "<<i<<"  : ";
            	// cromosom initial = cromosom last
               for(int j=0;j<sum_city;j++)
               {
               	//matrix_population[i]='\0';
      				gen_initial[i]=matrix_population[i];
      				//cout<<matrix_population[i][j]<<"  ";
                  save_file<<matrix_population[i][j]<<"  ";
               	////cout<<endl;
      			}
           	}
           	else
            {
           		t++; //automatic
               //cout<<" Individual new to "<<i<<"  : ";
               save_file<<" Individual new to "<<i<<"  : ";
            	// cromosom initial = cromosom initial
            	for(int j=0;j<sum_city;j++)
               {
               	//matrix_population[i]='\0';
      				matrix_population[i]=gen_initial[i];
      				//cout<<matrix_population[i][j]<<"  ";
               	save_file<<matrix_population[i][j]<<"  ";
               	////cout<<endl;
      			}
           	}
         }
         else{
         	t++; //automatic
            //cout<<" Individual new to "<<i<<"  : ";
            save_file<<" Individual new to "<<i<<"  : ";
            // cromosom initial = cromosom initial
            for(int j=0;j<sum_city;j++)
            {
            	//matrix_population[i]='\0';
      			matrix_population[i]=gen_initial[i];
      			//cout<<matrix_population[i][j]<<"  ";
               save_file<<matrix_population[i][j]<<"  ";
               ////cout<<endl;
            }
         }

        }while(t<=p);
        //cout<<"\n\n Individual new to "<<i<<" last : ";
        save_file<<"\n\n Individual new to "<<i<<" last : ";
        for(int j=0;j<sum_city;j++)
        {
        		//matrix_population[i]='\0';
            //cout<<gen_initial[i][j]<<"  ";
            save_file<<gen_initial[i][j]<<"  ";
        }
        //cout<<endl;
        save_file<<endl;
   }

}

void class_TSP::fitness(int pop_size)
{
int fb,fk,i;
result_fitness.setSize(pop_size);
//cout<<"\n============================\n";
//cout<<"\nresult localsearch :\n";
for(i=0;i<pop_size;i++)
   {
   	for(int j=0;j<sum_city;j++)
      {
      	//cout<<gen_initial[i][j]<<"  ";
      }
      result_evaluation[i]=value_z(gen_initial[i]);
      //cout<<"\nvalue_evaluation = "<<result_evaluation[i]<<"\n";
      //cout<<endl;
   }

//get max-min value evaluation
//cout<<"\nfind value max\n";
fb=result_evaluation[0];
////cout<<"fb initial ="<<fb<<"\n";
i=0;
do{
////cout<<"\ni ="<<i<<"\n";
   if(fb<result_evaluation[i+1]){
      if(i==(pop_size-1)){
      	break;
      }
   	////cout<<"\nfb<result_evaluation[i+1]"<<result_evaluation[i+1]<<"\n";
   	fb=result_evaluation[i+1];
      ////cout<<"\nfb initial ="<<fb<<"\n";
      i++;
   }
   else if(fb>=result_evaluation[i+1]){
   	if(i==(pop_size-1)){
      	break;
      }
   	////cout<<"\nfb>=result_evaluation[i+1]"<<result_evaluation[i+1]<<"\n";
      ////cout<<"\nfb initial ="<<fb<<"\n";
   	i++;
   	//continue;
   }
}while(i<pop_size);

//cout<<"fb ="<<fb<<"\n";

//cout<<"\nfind value min\n";
fk=result_evaluation[0];
////cout<<"fk initial ="<<fk<<"\n";
i=0;
do{
////cout<<"\ni ="<<i<<"\n";
   if(fk<result_evaluation[i+1]){
   	if(i==(pop_size-1)){
      	break;
      }
   	////cout<<"\nfk<result_evaluation[i+1]\n";
      ////cout<<"\nfk initial ="<<fk<<"\n";
   	i++;
   	//continue;
   }
   else if(fk>=result_evaluation[i+1]){
   	if(i==(pop_size-1)){
      	break;
      }
   	////cout<<"\nfk>=result_evaluation[i+1]\n";
   	fk=result_evaluation[i+1];
      ////cout<<"\nfk initial ="<<fk<<"\n";
      i++;
   }
}while(i<pop_size);

//cout<<"fk ="<<fk<<"\n";

//result fitness
//cout<<"\nresult fitness:\n";
for(i=0;i<pop_size;i++)
   {  //cout<<"Individual to->"<<i<<" : ";
   	for(int j=0;j<sum_city;j++)
      {
      	//cout<<gen_initial[i][j]<<"  ";
      }
      result_evaluation[i]=value_z(gen_initial[i]);
      result_fitness[i]=fb+fk-result_evaluation[i];
      //cout<<" : "<<result_fitness[i]<<"\n";
      //cout<<endl;
   }
}

void class_TSP::selection_crossover(float pc,int pop_size)
{
int i,k,check_same,l,check_fitness,index_k,sum_mother,step;
SimpleIArray i_rand;
i_rand.setSize(3);
SimpleIArray result_selection_crossover;
result_selection_crossover.setSize(pop_size);
result_mother_crossover.setSize(pop_size);
float ri;
//cout<<"\nresult selection initial crossover:\n";
for(i=0;i<pop_size;i++)
   {

   create_again:
	i_rand[0]=random(pop_size);
   step=random(pop_size)+i;
   ////cout<<"\ni_rand["<<k<<"]= "<<i_rand[k]<<"\n";
   k=1;
	do{
   	i_rand[k]=fmod(i_rand[k-1]+step,pop_size);
   	k++;
   }while(k!=3);

   //check, What cromosom is same
   for(k=0;k<3;k++){
      check_same=i_rand[k];
   	for(l=(k+1);l<3;l++){
   		if(check_same==i_rand[l]){
         	goto create_again;
      	}
     	}
   }
      
   k=0;
	do{
   	//cout<<"Individual to->"<<i_rand[k]<<" : "<<result_fitness[i_rand[k]]<<"\n";
   	k++;
   }while(k!=3);

   //find value fitness upper
   check_fitness=result_fitness[i_rand[0]];
   index_k=i_rand[0];
   for(k=0;k<3;k++){
   	for(l=(k+1);l<3;l++){
   		if(check_fitness<result_fitness[i_rand[l]]){
         	check_fitness=result_fitness[i_rand[l]];
            index_k=i_rand[l];
      	}
     	}
   }
   	//result selection crossover
      result_selection_crossover[i]=index_k;
   	//cout<<"upper Individual to->"<<index_k<<" : "<<check_fitness<<"\n";
      //cout<<endl;
   }

	//result turnament will become initial mother
	//cout<<"\nresult turnament will become initial mother:\n";
	for(i=0;i<pop_size;i++){
	//cout<<"Individual to->"<<result_selection_crossover[i]<<" : "<<result_fitness[result_selection_crossover[i]]<<" ";
   //cout<<endl;
   }

   //generate ri[0,1]
   //cout<<"\ninitial mother crossover:\n";
   sum_mother=0;
	for(i=0;i<pop_size;i++){
   ri=random(1000)/1000.0;
   	if(ri<pc){
      result_mother_crossover[sum_mother]=result_selection_crossover[i];
      //cout<<"Individual to->"<<result_selection_crossover[i]<<" : "<<ri<<" --> mother crossover ";
      sum_mother++;
      }
      else{
      //cout<<"Individual to->"<<result_selection_crossover[i]<<" : "<<ri<<" ";
      }
   //cout<<endl;
   }
   //cout<<"\nSum initial mother ="<<sum_mother<<"\n";
   
   //Determine mother crossover
   //cout<<"\nmother crossover:\n";
   if(sum_mother%2==1){
      sum_mother-=1;
   }
   sum_mother_crossover=sum_mother;    
	for(i=0;i<sum_mother;i++){
      //cout<<"Individual to->"<<result_mother_crossover[i]<<" : "<<result_fitness[result_mother_crossover[i]]<<" ";
   	//cout<<endl;
   }

}

void class_TSP::selection_mutation(float pm,int pop_size)
{
int i,k,check_same,l,check_fitness,index_k,sum_mother,step;
SimpleIArray i_rand;
i_rand.setSize(3);
SimpleIArray result_selection_mutation;
result_selection_mutation.setSize(pop_size);
result_mother_mutation.setSize(pop_size);
float ri;
//cout<<"\nresult selection initial mutation:\n";
for(i=0;i<pop_size;i++)
   {

   create_again:
	i_rand[0]=random(pop_size);
   step=random(pop_size)+i;
   ////cout<<"\ni_rand["<<k<<"]= "<<i_rand[k]<<"\n";
   k=1;
	do{
   	i_rand[k]=fmod(i_rand[k-1]+step,pop_size);
   	k++;
   }while(k!=3);

   //check, what cromosom s same
   for(k=0;k<3;k++){
      check_same=i_rand[k];
   	for(l=(k+1);l<3;l++){
   		if(check_same==i_rand[l]){
         	goto create_again;
      	}
     	}
   }
      
   k=0;
	do{
   	//cout<<"Individual to->"<<i_rand[k]<<" : "<<result_fitness[i_rand[k]]<<"\n";
   	k++;
   }while(k!=3);

   //find value fitness upper
   check_fitness=result_fitness[i_rand[0]];
   index_k=i_rand[0];
   for(k=0;k<3;k++){
   	for(l=(k+1);l<3;l++){
   		if(check_fitness<result_fitness[i_rand[l]]){
         	check_fitness=result_fitness[i_rand[l]];
            index_k=i_rand[l];
      	}
     	}
   }
   	//result selection mutation
      result_selection_mutation[i]=index_k;
   	//cout<<"upper Individual to->"<<index_k<<" : "<<check_fitness<<"\n";
      //cout<<endl;
   }

	//result turnament will be initial mother
	//cout<<"\nresult turnament will be initial mother:\n";
	for(i=0;i<pop_size;i++){
	//cout<<"Individual to->"<<result_selection_mutation[i]<<" : "<<result_fitness[result_selection_mutation[i]]<<" ";
   //cout<<endl;
   }

   //generate ri[0,1]
   //cout<<"\ninitial mother mutation:\n";
   sum_mother=0;
	for(i=0;i<pop_size;i++){
   ri=random(100)/(1000.0);
   	if(ri<pm){
      result_mother_mutation[sum_mother]=result_selection_mutation[i];
      //cout<<"Individual to->"<<result_selection_mutation[i]<<" : "<<ri<<" --> mother mutation ";
      sum_mother++;
      }
      else{
      //cout<<"Individual to->"<<result_selection_mutation[i]<<" : "<<ri<<" ";
      }
   //cout<<endl;
   }
   //cout<<"\nSum initial mother ="<<sum_mother<<"\n";
   
   //Determine mother mutation
   //cout<<"\nmother mutation:\n";
   //if(sum_mother%2==1){
      //sum_mother-=1;
   //}
   sum_mother_mutation=sum_mother;
	for(i=0;i<sum_mother;i++){
      //cout<<"Individual to->"<<result_mother_mutation[i]<<" : "<<result_fitness[result_mother_mutation[i]]<<" ";
   	//cout<<endl;
   }
}

void class_TSP::crossover_pmx(int pop_size)
{
int i,pos_string,bound_string,temp_1,temp_2,check_value;
temp_string.setSize(pop_size);
 //display mother crossover
 //cout<<"\nDisplay mother crossover :\n";
 for(i=0;i<sum_mother_crossover;i++){
      //cout<<"Individual to->"<<result_mother_crossover[i]<<" : "<<result_fitness[result_mother_crossover[i]]<<" ";
   	//cout<<endl;
   }

 //cout<<"\nSaving substring to temp_string :\n";
 for(i=0;i<sum_mother_crossover;i++){
      //cout<<"Individual to->"<<result_mother_crossover[i]<<" : ";
      for(int j=0;j<sum_city;j++){
      	//temp_string[i]=gen_initial[result_mother_crossover[i]];
      	//cout<<gen_initial[result_mother_crossover[i]][j]<<" ";
      }
   	//cout<<endl;
 }
 
 //Choose substring with random
 //cout<<"\nChoose substring with random :\n";
 for(i=0;i<sum_mother_crossover;i++){
      //cout<<"Individual to->"<<result_mother_crossover[i]<<" : ";
      for(int j=0;j<sum_city;j++){
      	temp_string[i]=gen_initial[result_mother_crossover[i]];
      	//cout<<temp_string[i][j]<<" ";
      }
   	//cout<<endl;

      //exchange substring pairing(@ two gen)
      if((i+1)%2==0){
      	do{
         pos_string=random(sum_city);
         }while(pos_string>(sum_city/2));
         //cout<<"\npos_string ="<<pos_string<<"\n";
         bound_string=pos_string+(sum_city/2);

         //start exchange substring
         //cout<<"\nStart exchange substring :\n";
         for(int k=pos_string;k<bound_string;k++){
         //cout<<"\npos_string ="<<k<<"\n";
         	temp_1=temp_string[i][k];
            //cout<<"temp_string["<<(i-1)<<"]]["<<k<<"] ="<<temp_1<<"\n";
            temp_2=temp_string[i-1][k];
            temp_string[i][k]=temp_2;
            //cout<<"temp_string["<<(i)<<"]["<<k<<"] ="<<temp_string[i][k]<<"\n";
            temp_string[i-1][k]=temp_1;
            //cout<<"temp_string["<<(i-1)<<"]["<<k<<"] ="<<temp_string[i-1][k]<<"\n";
         }

         //Display result exchange
         //cout<<"\nresult exchange pairing two :\n";
         for(int l=(i-1);l<=i;l++){
      	//cout<<"Individual to->"<<result_mother_crossover[l]<<" : ";
         	for(int j=0;j<sum_city;j++){
      			//cout<<temp_string[l][j]<<" ";
      		}
         //cout<<endl;
         }

         //Determine relation
   		////cout<<"\nDetermine relation \n";
         for(int l=(i-1);l<=i;l++){
         	//condition index <pos_string
         	//check_again:
            ////cout<<"\ncondition index <pos_string :\n";
         	for(int ii=0;ii<pos_string;ii++){
         		check_value=temp_string[l][ii];
               ////cout<<"\nii ="<<ii<<"\n";
               ////cout<<"\ncheck_value_initial ="<<check_value<<"\n";
            	check_again1:
               ////cout<<"\ncheck_value_initial_afterGoto ="<<check_value<<"\n";
         		for(int kk=pos_string;kk<bound_string;kk++){
               	////cout<<"\ntemp_string["<<l<<"]["<<kk<<"] ="<<temp_string[l][kk]<<"\n";
            		if(check_value==temp_string[l][kk]){
                  	//condition to proto child 1
                  	if(l==(i-1)){
               			check_value=temp_string[i][kk];
                     }
                     //condition to proto child 2
                     else if(l==i){
               			check_value=temp_string[i-1][kk];
                     }
                     ////cout<<"\ncheck_value ="<<check_value<<"\n";
                     //getch();
                  	temp_string[l][ii]=check_value;
                     ////cout<<"\ntemp_string_update["<<l<<"]["<<ii<<"] ="<<temp_string[l][ii]<<"\n";
                  	goto check_again1;
               	}
            	}
         	}
            
         	//condition ii >= bound_string
            ////cout<<"\ncondition index >= bound_string :\n";
         	for(int ii=bound_string;ii<sum_city;ii++){
         		check_value=temp_string[l][ii];
               ////cout<<"\nii ="<<ii<<"\n";
               ////cout<<"\ncheck_value_initial ="<<check_value<<"\n";
            	check_again2:
         		for(int kk=pos_string;kk<bound_string;kk++){
               	////cout<<"\ntemp_string["<<l<<"]["<<kk<<"] ="<<temp_string[l][kk]<<"\n";
            		if(check_value==temp_string[l][kk]){
                  	//condition to proto child 1
               		if(l==(i-1)){
               			check_value=temp_string[i][kk];
                     }
                     //condition to proto child 2
                     else if(l==i){
               			check_value=temp_string[i-1][kk];
                     }
                     ////cout<<"\ncheck_value ="<<check_value<<"\n";
                     //getch();
                  	temp_string[l][ii]=check_value;
                     ////cout<<"\ntemp_string_update["<<l<<"]["<<ii<<"] ="<<temp_string[l][ii]<<"\n";
                  	goto check_again2;
               	}
            	}
         	} 
      	}
      }
   }

   //result exchange substring (offspring from crossover)
   //cout<<"\nDisplay offspring from crossover :\n";
   for(i=0;i<sum_mother_crossover;i++){
      //cout<<"Individual to->"<<result_mother_crossover[i]<<" : ";
      for(int j=0;j<sum_city;j++){
      	//cout<<temp_string[i][j]<<" ";
      }      
   	//cout<<endl;
   }   
}

void class_TSP::mutation_bim(int pop_size)
{
int i,pos_string,temp_1,temp_2,bound_string;
temp_string2.setSize(pop_size);
	//cout<<"\n==========================================\n";
   //cout<<"process mutation_bim :\n";
	if(sum_mother_mutation==0){
   	//cout<<"> process mutation_bim nothing, because mutation have not offspring\n";
   }
   else{
   	//display mother mutation
 		//cout<<"\nDisplay mother mutation :\n";
 		for(i=0;i<sum_mother_mutation;i++){
      	//cout<<"Individual to->"<<result_mother_mutation[i]<<" : "<<result_fitness[result_mother_mutation[i]]<<" ";
   		//cout<<endl;
   	}

      //creating temporary mother mutation to temp_string2
      //cout<<"\nSaving string to temp_string2 :\n";
 		for(i=0;i<sum_mother_mutation;i++){
      	//cout<<"Individual to->"<<result_mother_mutation[i]<<" : ";
      	for(int j=0;j<sum_city;j++){
      		temp_string2[i]=gen_initial[result_mother_mutation[i]];
      		//cout<<temp_string2[i][j]<<" ";
      	}
         //cout<<" : "<<result_fitness[result_mother_mutation[i]]<<" ";
   		//cout<<endl;
 		}

      //Determine offspring mutation
      for(i=0;i<sum_mother_mutation;i++){
      	pos_string=random(sum_city);
         bound_string=pos_string+1;
      	//cout<<"\npos_string ="<<pos_string<<"\n";
         temp_1=temp_string2[i][pos_string];
         temp_2=(sum_city-1)-temp_1;
         temp_string2[i][pos_string]=temp_2;
         //cout<<"temp_string2["<<i<<"]["<<pos_string<<"] ="<<temp_string2[i][pos_string]<<"\n";
         //condition index < pos_string
         for(int jj=0;jj<pos_string;jj++){
         	if(temp_2==temp_string2[i][jj]){
         		temp_string2[i][jj]=temp_1;
         		//cout<<"temp_string2_update["<<i<<"]["<<jj<<"] ="<<temp_string2[i][jj]<<"\n";
         	}
         }
         //condition index > bound_string
         for(int jj=bound_string;jj<sum_city;jj++){
         	if(temp_2==temp_string2[i][jj]){
         		temp_string2[i][jj]=temp_1;
         		//cout<<"temp_string2_update["<<i<<"]["<<jj<<"] ="<<temp_string2[i][jj]<<"\n";
         	}
         }
      }

      //display offspring mutation
      //cout<<"\ndisplay offspring mutation :\n";
 		for(i=0;i<sum_mother_mutation;i++){
      	//cout<<"Individual to->"<<result_mother_mutation[i]<<" : ";
      	for(int j=0;j<sum_city;j++){
      		//cout<<temp_string2[i][j]<<" ";
      	}
   		//cout<<endl;
 		}              
   }
}

void class_TSP::cluster_offspring_crossover_mutation(int pop_size)
{
int i,sum_mother;
sum_mother=(sum_mother_crossover+sum_mother_mutation); //Sum pop_size offspring
//cout<<"sum_mother ="<<sum_mother<<"\n";
result_offspring.setSize(2*pop_size);
	//cout<<"\n===================================\n";
	//display offspring from crossover
   //cout<<"\nDisplay offspring from crossover :\n";
   for(i=0;i<sum_mother_crossover;i++){
      //cout<<"Individual to->"<<result_mother_crossover[i]<<" : ";
      for(int j=0;j<sum_city;j++){
         result_offspring[i]=temp_string[i];
      	//cout<<temp_string[i][j]<<" ";
      }
   	//cout<<endl;
   }

	//display offspring mutation
	//cout<<"\ndisplay offspring mutation :\n";
	for(i=0;i<sum_mother_mutation;i++){
		//cout<<"Individual to->"<<result_mother_mutation[i]<<" : ";
		for(int j=0;j<sum_city;j++){
       	result_offspring[i+sum_mother_crossover]=temp_string2[i];
			//cout<<temp_string2[i][j]<<" ";
		}
	//cout<<endl;
	}

   //cluster offsprings crossover + mutation
   //cout<<"\ndisplay cluster offspring crossover and mutation :\n";
   for(i=0;i<sum_mother;i++){
		//cout<<"Individual to->"<<i<<" : ";
		for(int j=0;j<sum_city;j++){
      	//matrix_population[i]=result_offspring[i]; //update matrix_population
			//cout<<result_offspring[i][j]<<" ";
		}
	//cout<<endl;
	}
}

void class_TSP::localsearch2(int pop_size,float epsilon, int p)
{
ofstream save_file("output_localsearch_offspring.txt");
int sum_mother;
int k1,k2; 					// index for exchange gen                
int temp1,t,temp_evaluation;
float e_random;
sum_mother=(sum_mother_crossover+sum_mother_mutation); //Sum pop_size offspring
//cout<<"sum_mother ="<<sum_mother<<"\n";
result_evaluation.setSize(2*pop_size);
gen_initial2.setSize(2*pop_size); //patching result local search offspring
for(int i=0;i<sum_mother;i++)
   {
   	//cout<<"\n=====================================\n";
   	//cout<<"Individual to "<<i<<" : ";
      save_file<<"\n=====================================\n";
      save_file<<"Individual to "<<i<<" : ";
   	for(int j=0;j<sum_city;j++)
      {
         //if(i<=sum_mother_crossover){
      		//gen_initial2[i]=temp_string[i];
         //}
         //else if(i>sum_mother_crossover){
      		//gen_initial2[i]=temp_string2[i-(sum_mother_crossover+1)];
         //}
         gen_initial2[i]=result_offspring[i];
      	//cout<<result_offspring[i][j]<<"  ";
         save_file<<result_offspring[i][j]<<"  ";
      }
      //cout<<endl;
      save_file<<endl;

      //find result evaluation gen initial
      result_evaluation[i]=value_z(result_offspring[i]);
      temp_evaluation=result_evaluation[i];
      //cout<<"\nresult_evaluation initial = "<<result_evaluation[i]<<"\n";
      save_file<<"\nresult_evaluation initial = "<<result_evaluation[i]<<"\n";

      t=0;
      do{
      //cout<<"\n> exchange gen t ="<<t<<"\n";
      //cout<<" Individual to "<<i<<"  : ";
      save_file<<"\n> exchange gen t ="<<t<<"\n";
      save_file<<" Individual to "<<i<<"  : ";
         do{
         	k1=random(sum_city);
           }
         while(k1==0);
         k2= k1<(sum_city-1) ? k2=k1+1 : k2=k1-1;   	// if k2=k1<(sum_city-1) else k2=k1+1 or k2=k1-1

         //exchange position gen
         temp1=result_offspring[i][k1];
         result_offspring[i][k1]=result_offspring[i][k2];
         result_offspring[i][k2]=temp1;
         for(int j=0;j<sum_city;j++)
         {
      		//gen_initial2[i][j]=result_offspring[i][j];
      		//cout<<result_offspring[i][j]<<"  ";
         	save_file<<result_offspring[i][j]<<"  ";
      	}

         //find result evaluation gen initial after exchange
         result_evaluation[i]=value_z(result_offspring[i]);
         //cout<<"\n result_evaluation stlh di exchange = "<<result_evaluation[i]<<"\n";
         save_file<<"\n result_evaluation stlh di exchange = "<<result_evaluation[i]<<"\n";

         //condition for consideration result_evaluation initial with after exchange
         if(result_evaluation[i]<temp_evaluation)
         {
         	result_evaluation[i]=value_z(result_offspring[i]);
      		temp_evaluation=result_evaluation[i];
            //cout<<"\n result_evaluation initial = "<<result_evaluation[i]<<"\n";
            save_file<<"\n result_evaluation initial = "<<result_evaluation[i]<<"\n";
         	t=0;
            //cout<<" Individual new to "<<i<<"  : ";
            save_file<<" Individual new to "<<i<<"  : ";
            // cromosom initial = cromosom last
            for(int j=0;j<sum_city;j++)
            	{
               	//result_offspring[i]='\0';
      				gen_initial2[i]=result_offspring[i];
      				//cout<<result_offspring[i][j]<<"  ";
               	save_file<<result_offspring[i][j]<<"  ";
               	////cout<<endl;
      			}
         }
         else if(result_evaluation[i]==temp_evaluation)
         {
           	e_random=random(1000)/1000.0;
           	//cout<<"\n e_random ="<<e_random<<"\n";
            save_file<<"\n e_random ="<<e_random<<"\n";
           	if(e_random<=epsilon)
            {
            	result_evaluation[i]=value_z(result_offspring[i]);
      			temp_evaluation=result_evaluation[i];
               //cout<<"\n result_evaluation initial = "<<result_evaluation[i]<<"\n";
               save_file<<"\n result_evaluation initial = "<<result_evaluation[i]<<"\n";
           		t=0;
               //cout<<" Individual new to "<<i<<"  : ";
               save_file<<" Individual new to "<<i<<"  : ";
            	// cromosom initial = cromosom last
               for(int j=0;j<sum_city;j++)
               {
               	//result_offspring[i]='\0';
      				gen_initial2[i]=result_offspring[i];
      				//cout<<result_offspring[i][j]<<"  ";
                  save_file<<result_offspring[i][j]<<"  ";
               	////cout<<endl;
      			}
           	}
           	else
            {
           		t++; //automatic
               //cout<<" Individual new to "<<i<<"  : ";
               save_file<<" Individual new to "<<i<<"  : ";
            	// cromosom initial = cromosom initial
            	for(int j=0;j<sum_city;j++)
               {
               	//result_offspring[i]='\0';
      				result_offspring[i]=gen_initial2[i];
      				//cout<<result_offspring[i][j]<<"  ";
               	save_file<<result_offspring[i][j]<<"  ";
               	////cout<<endl;
      			}
           	}
         }
         else{
         	t++; //automatic
            //cout<<" Individual new to "<<i<<"  : ";
            save_file<<" Individual new to "<<i<<"  : ";
            // cromosom initial = cromosom initial
            for(int j=0;j<sum_city;j++)
            {
            	//result_offspring[i]='\0';
      			result_offspring[i]=gen_initial2[i];
      			//cout<<result_offspring[i][j]<<"  ";
               save_file<<result_offspring[i][j]<<"  ";
               ////cout<<endl;
            }
         }
        }while(t<=p);
        //cout<<"\n\n Individual new to "<<i<<" last : ";
        save_file<<"\n\n Individual new to "<<i<<" last : ";
        for(int j=0;j<sum_city;j++)
        {
        		//result_offspring[i]='\0';
            //cout<<gen_initial2[i][j]<<"  ";
            save_file<<gen_initial2[i][j]<<"  ";
        }
        //cout<<endl;
        save_file<<endl;
   }
}

void class_TSP::show_population_new(int pop_size)
{
int i,j;
//SimpleArray<SimpleIArray> temp_result;
//temp_result.setSize((pop_size+sum_mother_crossover+sum_mother_mutation));
result_population_new.setSize(pop_size*pop_size);
	//cout<<"\n===================================\n";
	//display offspring from crossover
   //cout<<"\ndisplay population initial :\n";
   for(i=0;i<pop_size;i++){
      ////cout<<"Individual to->"<<i<<" : ";
      for(int j=0;j<sum_city;j++){
         result_population_new[i]=gen_initial[i];
      	////cout<<gen_initial[i][j]<<" ";
      }
   	////cout<<endl;
   }

	//display offspring mutation
	//cout<<"\ndisplay population offspring :\n";
	for(i=0;i<(sum_mother_crossover+sum_mother_mutation);i++){
		////cout<<"Individual to->"<<i<<" : ";
		for(int j=0;j<sum_city;j++){
       	result_population_new[i+pop_size]=gen_initial2[i];
      	////cout<<gen_initial2[i][j]<<" ";
		}
	////cout<<endl;
	}

   //display cluster population new
   //cout<<"\ndisplay population cluster:\n";
   for(i=0;i<(pop_size+sum_mother_crossover+sum_mother_mutation);i++){
		//cout<<"Individual to->"<<i<<" : ";
		for(int j=0;j<sum_city;j++){
			//cout<<result_population_new[i][j]<<" ";
		}
      result_evaluation[i]=value_z(result_population_new[i]);
      //cout<<" : "<<result_evaluation[i]<<"\n";
	}

   //process sorting
   ////cout<<"\nprocess sorting :\n";
   for(i=0;i<((pop_size+sum_mother_crossover+sum_mother_mutation)-1);i++){
     	for(j=(i+1);j<(pop_size+sum_mother_crossover+sum_mother_mutation);j++){
      	if(value_z(result_population_new[i])>value_z(result_population_new[j])){
            for(int ij=0;ij<sum_city;ij++){
            result_population_new[i][ij]=(result_population_new[i][ij]+result_population_new[j][ij]);
            result_population_new[j][ij]=(result_population_new[i][ij]-result_population_new[j][ij]);
            result_population_new[i][ij]=(result_population_new[i][ij]-result_population_new[j][ij]);
            }
         }
   	}
	}

   //display population cluster result sorting
   //cout<<"\ndisplay population cluster result sorting:\n";
   for(i=0;i<(pop_size+sum_mother_crossover+sum_mother_mutation);i++){
		//cout<<"Individual to->"<<i<<" : ";
		for(int j=0;j<sum_city;j++){
			//cout<<result_population_new[i][j]<<" ";
		}
      result_evaluation[i]=value_z(result_population_new[i]);
      //cout<<" : "<<result_evaluation[i]<<"\n";
	}

   cout<<".!";
   //display population cluster count equal pop_size
   cout<<"\ndisplay population cluster count equal pop_size:\n";
   for(i=0;i<pop_size;i++){
		cout<<"Individual to->"<<i<<" : ";
		for(int j=0;j<sum_city;j++){
      	matrix_population[i]=result_population_new[i]; //update matrix_population
			cout<<matrix_population[i][j]<<" ";
		}
      result_evaluation[i]=value_z(result_population_new[i]);
      cout<<" : "<<result_evaluation[i]<<"\n";
	}
}




