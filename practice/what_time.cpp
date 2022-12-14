#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct TimeOfDay{
    unsigned int hour {0};
    unsigned int minute {0};
};

void print_time (TimeOfDay the_time){
    std::cout << the_time.hour << ":" << the_time.minute;
}

/* parse_time(input)
Given a string, attempt to parse the contents into an hour and minute
and return a TimeOfDay object containing the result.

Exceptions should be thrown in the following cases. The cases 
must be checked in the order below.
    - If a string does not contain two numerical fields separated by a colon
    (eg "10:06" or "17:10", but not "6" or "10:"), 
    throw std::domain_error (NOT std::invalid_argument).
    - If hour is not in the range 0 - 23 or the minute is not in the range
    0 - 59, throw std::out_of_range

    (For this exercise, assume that if std::stoi finished successfully, 
    the value returned is a valid numerical interpretation of the input string)
    */

TimeOfDay parse_time( std::string input){

    std::string before_colon {};
    std::string after_colon {};

    bool found {false} ;

    for(auto c:input){
        if(c == ':'){
            found = true;
        }

        else if(found){
            after_colon += c;
        }

        else{
            before_colon += c;
        }
    }
    //std::cout << "Before: " << before_colon << std::endl;
    //std::cout << "After: " << after_colon << std::endl;

    


    TimeOfDay the_time {};
    try{
        the_time.hour = std::stoi(before_colon);
        the_time.minute = std::stoi(after_colon);
    }catch (std::invalid_argument &e){
        throw std::domain_error {"Invalid Time"};
        std::cout << std::endl;
    }

    if (0 < the_time.hour || the_time.hour > 23 || the_time.minute < 0 || the_time.minute > 59){
        throw std::out_of_range {"Invalid time"};
    }
    

    return the_time;

}


int main(){
    std::string input_string;

    std::cout << "What time is it? ";
    std::getline( std::cin, input_string);
    std::cout << "You entred " << input_string << std::endl;

    // Task: Handle the error cases
    try{
        TimeOfDay T { parse_time(input_string) };
        std::cout << "The time is ";
        print_time(T);
        std::cout << std::endl;
    }catch (std::domain_error &e){
        std::cout << "string does not contain two numerical fields separated by a colon" << std::endl;
    }catch (std::out_of_range &e){
        std::cout << "Hours or Minutes not in range" << std::endl;
    }
    

    return 0;
}

