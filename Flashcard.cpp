#include <iostream>
#include <vector>
#include <string>

class Card{
	
	public:
	std::string front;
	std::string back;
	bool reviewed = false;
	Card (std::string f, std::string b){
			front = f;
			back = b;
		
	}

};

class Flashcard{
		std::vector<Card> Cards;
		int counter = 1;
	public:
	    void add_card(Card card){
		    Cards.push_back(card);
	        
	    }
    	void run(){
    		
    		while (!Cards.empty()){
    				if (Cards.front().reviewed == true){
    					Cards.erase(Cards.begin()); //remove the reviewed card.
                    
    				}
    				else{

    					std::string response;
    					std::cout << "Flashcard "  << counter << "\n";
    					std::cout << Cards.front().front << "\n";
    					std::getline(std::cin, response);
    					for (char &c : response) { c = std::tolower(c); }  // make them lowercase

                        

                        //correct?
    					if (response == Cards.front().back){
    						std::cout << "Correct" << "\n";
    						Cards.front().reviewed = true;
    					}
                        //wrong?
    					else {
    						std::cout << "Wrong" << "\n";
                            // move card to the back of the vector
                            Cards.push_back(Cards.front());
                            Cards.erase(Cards.begin());
    					}
    					counter++;
    
    					// REVIEW ANOTHER CARD
    					
    					char review_again;
    					std::cout << "would you like to review another card. (y or n)" << "\n";
    					std::cin >> review_again;
                        std::cin.ignore(); // Discards the leftover '\n' character from the stream buffer
    					switch (review_again){
    						case 'y':
    							break;
    						case 'n':
    							return; //exit program
    						default:
    							std::cout << "please select y or n" << "\n";
                                break;
    							
    					}
    		
    		
    
    						
    					
    					
    					}
    					
    					
    				}
            // IF Cards are indeed empty
    		std::cout << "You have no cards for review." << "\n";
            return;
    		}
    	};


int main(){

    std::cout << "---------- WELCOME TO YOUR FLASHCARD APP --------------- "<< "\n";
    Flashcard app;
    // put a preset question
    Card d("what is the largest bone in the human body", "femur");
    app.add_card(d);

    //begine the app
    int option;
    while (1){
        std::cout << "What would You LIke to do." <<"\n";
        std::cout << "1. Begin Reviewing " << "\n";
        std::cout << "2. Add card " << "\n";

        std::cin >> option;
        std::cin.ignore(); // Discards the leftover '\n' character from the stream buffer
        switch (option){
            case 1:
                app.run();
                break;
            // put the case in curly braces  so the variables are created in a separate block of memory in our switch and destroyed at the end.
            // we do this to avoid the compiler skipping over our string variables if we run default.
            case 2: {

                std::string front;
                std::string back;
                std::cout << "Enter the question on the card?  " << "\n";
                std::getline(std::cin, front);
                std::cout << "Enter the answer? " << "\n";
                std::getline(std::cin, back);
                
                Card c(front, back);
                app.add_card(c);
                std::cout << "Card added successfully." << "\n";
                break;


            }
                

            default:
                std::cout << "please select 1 or 2" << "\n";
                break;

        }

        
        

}

return 0;
    
}