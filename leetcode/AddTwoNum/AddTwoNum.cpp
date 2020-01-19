#include <AddTwoNum.hpp>

ListNode* addTwoNum(ListNode* l1, ListNode* l2){

    ListNode* dummy = new ListNode(0);
    ListNode* l3 = dummy;
    int sum = 0, eps = 0; // eps is the residual to carry

    while(true){
        
        if (l1 != nullptr and l2 != nullptr) {
            
            sum = l1->val + l2->val + eps;
            l1 = l1->next;
            l2 = l2->next;

        } else if (l1 != nullptr) {

            sum = l1->val + eps;
            l1 = l1->next;

        } else if (l2 != nullptr) {

            sum = l2->val + eps;
            l2 = l2->next;

        } else {

            if (eps) {l3->next = new ListNode(1);} // IMPORTANT !! CARRY THE FIRST DIGIT IF NECESSARY!!
            break;
        
        }
    
        l3->next = new ListNode(sum % 10);
        eps = (int)sum / 10;
        l3 = l3->next;
    }
    
    l3 = dummy->next;
    delete dummy;

    return l3;
}

ListNode* vectorToListNode(const std::vector<int>& v){
    /* Construct ListNode from a vector */
    ListNode* dummy = new ListNode(0);
    ListNode* ln = dummy;

    for(auto&& item : v)
    {   
        ln->next = new ListNode(item);
        ln = ln->next;
    }
    
    ln = dummy->next;
    delete dummy;
    return ln;
}

unsigned long long int listNodeToInteger(ListNode* ln){
    /* Convert a ListNode back to integer */
    unsigned long long int factor = 1, num = 0;
    while(ln != nullptr){
        num += ln->val * factor;
        factor = factor * 10;
        ln = ln->next;
    }

    return num;
}

int main(void)
{
    /* LeetCode Add Two Numbers */
    std::string filename, line;
    
    std::cout << "Input File: ";
    std::cin >> filename;

    std::ifstream myfile (filename);

    if (myfile.is_open()){
        
        while(getline(myfile, line)){
            std::vector<int> v1 = stringToIntegerVector(line);
            getline(myfile, line);
            std::vector<int> v2 = stringToIntegerVector(line);

            ListNode* l1 = vectorToListNode(v1);
            ListNode* l2 = vectorToListNode(v2);

            ListNode* res = addTwoNum(l1, l2);

            std::cout << "Add "<< listNodeToInteger(l1) << " and " 
                      << listNodeToInteger(l2) << std::endl;
            std::cout << listNodeToInteger(res) << std::endl;

            delete l1, l2, res;
        } // endwhile
        
        myfile.close();
    } // endif

    return 0;
}
