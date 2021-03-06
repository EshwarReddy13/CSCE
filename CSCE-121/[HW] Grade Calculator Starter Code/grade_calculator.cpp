// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    double homeworkScore = 0;
    double examScore = 0;
    double lwScore = 0;
    double finalexamScore = 0;
    double readingScore = 0;
    double engagementScore = 0;
    int hwNumber=0;
    int lwNumber=0;
    int readingNumber=0;
    int engagementNumber=0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        // Adding the score to the appropraite variables depending on the category
        // Adding the number of hw's, lw's, etc to the appropraite variables
        if (category == "exam") {
            // TODO(student): process exam score
            examScore += score;
        } else if (category == "final-exam") {
            // TODO(student): process final score
            finalexamScore += score;
        } else if (category == "hw") {
            // TODO(student): process hw score
            homeworkScore += score;
            hwNumber += 1;
        } else if (category == "lw") {
            // TODO(student): process lw score
            // Checking if lw is 0 or not
            if(score == 0){
                lwScore += 0;
            }else{
                lwScore +=1;
            }
            lwNumber +=1;
            
        } else if (category == "reading") {
            // TODO(student): process reading score
            readingScore += score;
            readingNumber += 1;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
            engagementScore += score;
            engagementNumber += 1;
        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double reading = 0;
    double engagement = 0;

    //First we check whether the score is 0 or not 
    //If it is 0 then the average will be 0
    if(examScore == 0 && finalexamScore == 0){
        exam_average = 0;
    }else{
        //Checking if the final exam score is 0
        //If it is 0 then the exam average is the average of all the exams
        if(finalexamScore ==0){
            exam_average = examScore/3;
        //If it is not 0 then the exam average is the max of the final exam or the average of all the 3 exams
        }else{
            exam_average = std::max(finalexamScore,(examScore+finalexamScore)/3);
        }
    }

    if(hwNumber == 0){
        hw_average = 0;
    }else{
        hw_average = (homeworkScore/hwNumber);
    }

    if(lwNumber == 0){
        lw_average =0;
    }else{
        lw_average = (lwScore/lwNumber)*100;
    }

    if(readingNumber ==0){
        reading = 0;
    }else{
        reading = (readingScore/readingNumber);
    }
    //Checking if reading is greater than 85 since then it would be 100
    if(reading < 85){
        reading += 15;
    }else{
        reading = 100;
    }

    if(engagementNumber == 0){
        engagement=0;
    }else{
        engagement = (engagementScore/engagementNumber);
    }
    //Checking if engagement is greater than 85 since then it would be 100
    if(engagement < 85){
        engagement += 15;
    }else{
        engagement = 100;
    }

    // TODO(student): compute weighted total of components
    double weighted_total = 0;
    //Calculating the total using the weightage of all the modules from the syallabus 
    weighted_total = ( (0.4 * exam_average) + (0.4 * hw_average) + (0.1 * lw_average) + (0.05 * reading) + (0.05 * engagement) );

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    //Determining the grade depending on the weighted total
    if(weighted_total >= 90){
        final_letter_grade = 'A';
    }else if(weighted_total >= 80){
        final_letter_grade = 'B';
    }else if(weighted_total >= 70){
        final_letter_grade = 'C';
    }else if(weighted_total >= 60){
        final_letter_grade = 'D';
    }else{
        final_letter_grade = 'F';
    }

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
