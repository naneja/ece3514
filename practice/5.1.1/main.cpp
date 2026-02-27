#include <iostream>
#include <string>
class GameEntry {
    private:
        std::string name;
        int score;
    public:
        GameEntry(const std::string& n="", int s=0)
        : name{n}, score{s} {};
        const std::string& get_name() const{
            return name; 
        }
        int get_score() const{
            return score; 
        }
};


class Scoreboard {
    private:
        //dynamic memory GameEntry[cap]    
        GameEntry* board{nullptr};
        int capacity;       // capacity
        int num_entries{0}; // actual entries

    public:
        Scoreboard(int cap=10)
        : capacity{cap}, board{new GameEntry[cap]} {};
        
        // destructor (virtual if polymorphic)
        ~Scoreboard(){
            delete[] board;
        }

        int get_capacity() const{
            return capacity;
        }

        int get_num_entries() const{
            return num_entries;
        }

        const GameEntry& get_entry(int i) const{
            if (i<0 || i >= num_entries)
                throw std::out_of_range("Invalid index");
            return this->board[i];
        }

        void add(int score, const std::string& name);

        GameEntry remove(int i);
        
        Scoreboard(const Scoreboard& other) = delete;
        Scoreboard& operator=(const Scoreboard& other) = delete;

        Scoreboard(Scoreboard&& other) noexcept = delete;
        Scoreboard& operator=(Scoreboard&& other) noexcept = delete;
};


void Scoreboard::add(int score, const std::string& name) {
    bool is_space{num_entries < capacity};
    auto lowest_score{0};
    if (num_entries > 0)
        lowest_score = board[num_entries - 1].get_score();
    bool is_new_score_higher{score > lowest_score};

    if (is_space || is_new_score_higher) {//OR
        if (is_space) // no drop
            num_entries++;

        // shift any lower scores rightward 
        int j{num_entries-1}; //index for score
        while (j>0 && board[j-1].get_score() < score) {
            board[j] = board[j-1];  //shift right
            j--;
        }
        //assignment overloaded (temp stack copied to heap)
        board[j] = GameEntry(name, score);
    }
}

// Removes and returns the scoreboard entry at index i
GameEntry Scoreboard::remove(int i) {
    if (i<0 || i>=num_entries) 
        throw std::out_of_range("Invalid index");
    GameEntry temp{board[i]}; // save the entry to return

    //start from index to be removed 
    //and shift left till num_entries
    for (int j{i}; j<num_entries-1; j++) //count up from i
        board[j] = board[j+1];
    num_entries--; //reduce the entries by 1
    return temp; // return deleted for confirmation
}


void print_board(const Scoreboard &board){
    for (int i{0}; i<board.get_num_entries(); i++) {
        std::cout << i + 1 << ". " 
            << board.get_entry(i).get_name() << ": "
            << board.get_entry(i).get_score() << "\t";
    }
    std::cout << "\n";
}

int main() {
    Scoreboard board(5);  // capacity of 5

    board.add(800, "P1"); board.add(650, "P2");
    board.add(400, "P3"); board.add(360, "P4");
    board.add(240, "P5");

    std::cout << "Current Scoreboard:\n";
    print_board(board);

    board.add(700, "P3");

    std::cout << "\nUpdated Scoreboard:\n";
    print_board(board);
}