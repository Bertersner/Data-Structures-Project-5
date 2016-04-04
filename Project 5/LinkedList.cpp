
// Byron Burdette
// COP2535.0M1



/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                        MEMBER FUNCTION DEFINITIONS FOR THE CLASS "LinkedList"
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/





#include "LinkedList.h"                                                                        //    include class specification file






/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE "mainMenu" FUNCTION

        the purpose of this function is to display the purpose of the program for the user as well as a menu of options for the user to choose from
**********************************************************************************************************************************************************/
template <class T>                                                                            //    template prefix marks the beginning of the function template
void LinkedList<T>::mainMenu()                                                                //    begin function definition
{
    T input;                                                                                //    template variabel "input" holds the user's input
    char command;                                                                            //    char "command" holds the menue option chosen once it's been validated and converted to a char


    cout << setfill('*') << setw(79) << '*' << endl;                                                         //    introductory message
    cout << "* The purpose of this program is to demonstrate an appropriate use of linked  *" << endl        //    more message
        << "*    lists. Choose from one of the seven options below to manage a list of    *" << endl         //    still more message
        << "*    items. Type the letter corresponding to your command and press \"Enter\"   *" << endl;      //    a little more message
    cout << setfill('*') << setw(79) << '*' << endl << endl;                                                 //    some formatting, and we're done


    cout << "Type 'a' to add an item to the beginning of the list" << endl;                                   //    displays a menu option
    cout << "Type 'b' to add and item to the end of the list" << endl;                                        //    displays a menu option
    cout << "Type 'c' to remove the first item in the list" << endl;                                          //    displays a menu option
    cout << "Type 'd' to remove the last item in the list" << endl;                                           //    displays a menu option
    cout << "Type 'e' to remove a specified item from the list" << endl;                                      //    displays a menu option
    cout << "Type 'f' to display the list" << endl;                                                           //    displays a menu option
    cout << "Type 'q' to end the program" << endl << endl;                                                    //    displays a menu option



    while (true)                                                                                 //    loop here indefinitely. We give the user the option to manually break out of it later
    {
        cout << "Enter a command (a-q): ";                                                       //    prompt the user to enter a command
        getline(cin, input);                                                                     //    read the user's command
        command = validate(input);                                                               //    validate that an appropriate command was entered, then convert the command to a char "command"

        switch (command)                                                                         //    begin switch statement for char "command"
        {
        case 'a':                                                                                //    if the user chose option A
            cout << "Enter the item you wish to add to the beginning of the list: ";             //    display prompt
            getline(cin, input);                                                                 //    read in the item the user would like to add to the list
            addBeg(input);                                                                       //    add the item to the beginning of the list
            cout << "\"" << input << "\" was added to the top of the list" << endl << endl;      //    display confirmation message
            break;                                                                               //    break the switch statement so the user can choose another menu option
        case 'b':                                                                                //    if the user chooses option B
            cout << "enter the item you wish to add the to the end of the list: ";               //    display prompt
            getline(cin, input);                                                                 //    read in the item the user would like to add to the list
            addEnd(input);                                                                       //    add the item to the end of the list
            cout << "\"" << input << "\" was added to the bottom of the list" << endl << endl;   //    display confirmation message
            break;                                                                               //    break the switch statement so the user can choose another menu option
        case 'c':                                                                                //    if the user chooses option C
            removeBeg();                                                                         //    remove the first item in the list
            break;                                                                               //    break the switch statement so the user can choose another menu option
        case 'd':                                                                                //    if the user chooses option D
            removeEnd();                                                                         //    remove the last item in the list
            break;                                                                               //    break the switch statement so the user can choose another menu option
        case 'e':                                                                                //     if the user chooses option E
            cout << "Enter the item you wish to remove from the list: ";                         //     display prompt
            getline(cin, input);                                                                 //    read in the item the user wished to remove from the list
            remove(input);                                                                       //    remove the specified item from the list
            break;                                                                               //    break the switch statement so the user can choose another menu option
        case 'f':                                                                                //    if the user chooses option F
            displayList();                                                                       //    display the list
            cout << endl;                                                                        //    output a newline for nicer formatting
            break;                                                                               //    break the switch statement so the user can choose another menu option
        case 'q':                                                                                //    if the user chooses option Q
            cout << "Exiting program...";                                                        //    display exit prompt
            system("pause");                                                                     //    pause before terminating the program so the user can see the output
            exit (0);                                                                            //     terminate the program without errors
        }
    }
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE "mainMenu" FUNCTION
**********************************************************************************************************************************************************/




/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE "validate" FUNCTION

                the purpose of this function is to ensure the user chooses appropriate menu options ('a' 'b' 'c' 'd' 'e' 'f' and 'q')
**********************************************************************************************************************************************************/
template <class T>                                                                                 //    template prefix marks the beginning of the function template
char LinkedList<T>::validate(T s)                                                                  //    begin function definition
{
    bool flag = false;                                                                             //    false flag represents invalid input. True flag represents good input
    char c;                                                                                        //    we will store the validated menu option as a char

    while (!flag)                                                                                  //    as long as the user has entered an invalid menu option...
    {
        flag = true;                                                                               //    reset the flag

        if (s.length() > 1)                                                                        //    if user typed more than a single character...
            flag = false;                                                                          //    than we've got a bad input. Set the flag to false so we remain in the validation loop
        else                                                                                       //    otherwise...
        {
            c = s[0];                                                                              //    store the user's input as a char
            c = tolower(c);                                                                        //    and convert the char to lowercase

            if (c != 'a' && c != 'b' && c != 'c' && c != 'd' && c != 'e' && c != 'f' && c != 'q')    //    if the user input anything besides one of the seven expected values...
                flag = false;                                                                       //    than we've got bad input. Set the flag to false so we remain in the validation loop
        }

        if (!flag)                                                                                 //    if it turned out that we had bad input
        {
            cin.sync();                                                                            //    clear the input buffer
            cin.clear();                                                                           //    reset the cin I/O state flags

            cout << "Please enter correct input: ";                                                //    prompt the user to re-enter input
            getline(cin, s);                                                                       //    read the input
        }
    }                                                                                              //    end of the loop

    
    return c;                                                                                      //    once we make it this far, we have guarenteed good input. Return the input.
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE "validate" FUNCTION
**********************************************************************************************************************************************************/





/*********************************************************************************************************************************************************
                                                    THIS MARKS THE BEGINNING OF THE "addBeg" FUNCTION

                            the purpose of this function is to add a new ListNode to the top of the linked list
**********************************************************************************************************************************************************/
template <class T>                                                                               //    template prefix marks the beginning of the function template
void LinkedList<T>::addBeg(T value)                                                              //    begin function definition
{
    head = new ListNode(value, head);                                                            //    create a new ListNode at the top of the list
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE "addBeg" FUNCTION
**********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE "addEnd" FUNCTION

                            the purpose of this function is to add a new ListNode to the bottom of the linked list
**********************************************************************************************************************************************************/
template <class T>                                                                               //    template prefix marks the beginning of the function template
void LinkedList<T>::addEnd(T value)                                                              //    begin function definition
{
    if (head == NULL)                                                                            //    if the list is empty...
        head = new ListNode(value);                                                              //    then we can create the new ListNote at the top of the list
    else                                                                                         //    otherwise, the list must not be empty...
    {
        ListNode* nodePtr = head;                                                                //    we'll traverse the list by starting at the top and setting pointer "nodePtr" to the memory location of the head ListNode

        while (nodePtr->next != NULL)                                                            //    while we're not at the bottom of the list
            nodePtr = nodePtr->next;                                                             //    set noPtr to the next ListNode in the list

        nodePtr->next = new ListNode(value);                                                     //    create a new ListNode at the bottom of the list
    }
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE "addEnd" FUNCTION
**********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************
                                                    THIS MARKS THE BEGINNING OF THE "removeBeg" FUNCTION

                                        the purpose of this function is to remove the first ListNode in the linked list
**********************************************************************************************************************************************************/
template <class T>                                                                                 //    template prefix marks the beginning of the function template
void LinkedList<T>::removeBeg()                                                                    //    begin function definition
{
    if (!head)                                                                                     //    if the list is empty...
    {
        cout << "list empty..." << endl << endl;                                                   //    tell the user that the list is empty
        return;                                                                                    //    return to the main menu
    }

    ListNode* nodePtr = head;                                                                      //    otherwise, set nodePtr to the memory location of the head ListNode
    string item = head->value;                                                                     //    store the value of the head ListNode in string "item"
    head = head->next;                                                                             //    set the head ListNode to the second ListNode in the list
    delete nodePtr;                                                                                //    delete the previous ListNode
    cout << "removed " << item << " from the list..." << endl << endl;                             //    display that the node was deleted
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE "removeBeg" FUNCTION
**********************************************************************************************************************************************************/




/*********************************************************************************************************************************************************
                                        THIS MARKS THE BEGINNING OF THE "removeEnd" FUNCTION

                        the purpose of this function is to remove the last ListNode in the linked list
**********************************************************************************************************************************************************/
template <class T>                                                                             //    template prefix marks the beginning of the function template
void LinkedList<T>::removeEnd()                                                                //    begin function definition
{
    ListNode *nodePtr, *previousNodePtr;                                                       // create new ListNode pointers
    string item;                                                                               //    create a string for storing the value of the ListNode that will be deleted

    if (!head)                                                                                 //    if the list is empty, then we cant delete anything
    {
        cout << "list empty..." << endl << endl;                                               //    tell the user that the list was empty
        return;                                                                                //    return to the main menu
    }

    if (head->next == NULL)                                                                    //    otherwise, check if there's only one ListNode in the entire list
    {
        item = head->value;                                                                    //    store the value of the ListNode in "item"
        head = head->next;                                                                     //    set the ListNode to NULL
        cout << "removed " << item << " from the list..." << endl << endl;                     //    display which node was deleted
        return;                                                                                //    return to the main menu
    }

    nodePtr = head;                                                                            //    if we've made it this far, than there's multiple nodes in the list. We must traverse the list, and we'll star by setting nodePtr to the head of the list
    previousNodePtr = head;                                                                    //    we'll also set previousNodePointer to the head of the list

    while (nodePtr->next != NULL)                                                              //    while we're not at the bottom of the list
    {
        previousNodePtr = nodePtr;                                                             //    set the previous node to the current node
        nodePtr = nodePtr->next;                                                               //    move the current node to the next node down the list
    }

    item = nodePtr->value;                                                                     //    store the value of the last node in the list in "item"
    previousNodePtr->next = NULL;                                                              //    set the previous node as the last node in the list
    delete nodePtr;                                                                            //    delete the last node in the list
    cout << "removed " << item << " from the list..." << endl << endl;                         //    display which node was removed
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE "removeEnd" FUNCTION
**********************************************************************************************************************************************************/





/*********************************************************************************************************************************************************
                                                THIS MARKS THE BEGINNING OF THE "remove" FUNCTION

                    the purpose of this function is to remove the ListNode containing a specified value from the linked list
**********************************************************************************************************************************************************/
template <class T>                                                                             //    template prefix marks the beginning of the function template
void LinkedList<T>::remove(T value)                                                            //    begin function definition
{
    ListNode *nodePtr, *previousNodePtr;                                                       // create new ListNode pointers

    if (!head)                                                                                 //    if the list is empty, then we cant delete anything
    {
        cout << "list empty..." << endl << endl;                                               //    tell the user that the list was empty
        return;                                                                                //    return to the main menu
    }

    if (head->value == value)                                                                  //    otherwise, check and see if the head node is the one to be deleted
    {
        nodePtr = head;                                                                        //    set nodePtr to the head node in the list
        head = head->next;                                                                     //    move the head down one node
        delete nodePtr;                                                                        //    delete the old head node
        cout << "\"" << value << "\" was removed from the list" << endl << endl;               //    display that the node was removed
    }
    else                                                                                       //    otherwise, we'll need to traverse the list to find the correct node to remove
    {
        nodePtr = head;                                                                        //    we'll start at the top by setting nodePtr to the head node
        previousNodePtr = NULL;                                                                //    we must initialize previousNodePtr to something. I chose NULL

        while (nodePtr != NULL && nodePtr->value != value)                                     //    While we haven't hit the bottom of the list and we located the target node...
        {
            previousNodePtr = nodePtr;                                                         //    set previousNodePtr to nodePtr
            nodePtr = nodePtr->next;                                                           //    move nodePtr down to the next node
        }

        if (nodePtr)                                                                           //    if nodePtr is not a NULL pointer, than we have found our target node
        {
            previousNodePtr->next = nodePtr->next;                                             //    link the previous node to the node after the one to be deleted
            delete nodePtr;                                                                    //    delete the target node
            cout << "\"" << value << "\" was removed from the list" << endl << endl;           //    display that the node was removed from the list
        }
        else                                                                                   //    otherwise, we traversed the entire list without locating the target node
            cout << "Could not locate " << value << "..." << endl << endl;                     //    display that the target could not be located
    }
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE "remove" FUNCTION
**********************************************************************************************************************************************************/





/*********************************************************************************************************************************************************
                                            THIS MARKS THE BEGINNING OF THE "displayList" FUNCTION

                    the purpose of this function is to display the values contained in each of the ListNodes in the linked list
**********************************************************************************************************************************************************/
template <class T>                                                                             //    template prefix marks the beginning of the function template
void LinkedList<T>::displayList() const                                                        //    begin function definition
{
    ListNode* nodePtr;                                                                         //    create a ListNode pointer "nodePtr" which we'll use to traverse the linked list

    if (head)                                                                                  //    if the list is not empty...
        nodePtr = head;                                                                        //    set nodePtr to the top of the list
    else                                                                                       //    otherwise, the list must be empty
    {
        cout << "list empty..." << endl;                                                       //    tell the user that the list is empty
        return;                                                                                //    return to the main menu
    }
    
    cout << endl;                                                                              //    output a newline for nicer formatting
    while (nodePtr)                                                                            //    while we haven't reached the bottom of the list
    {
        cout << nodePtr->value << endl;                                                        //    display the value of the current node
        nodePtr = nodePtr->next;                                                               //    move down to the next node
    }
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE "displayList" FUNCTION
**********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************
                                                    THIS MARKS THE BEGINNING OF THE DESTRUCTOR

                        the purpose of this function is to deallocate memory allocated during the execution of the program
**********************************************************************************************************************************************************/
template <class T>                                                                             //    template prefix marks the beginning of the function template
LinkedList<T>::~LinkedList()                                                                   //    begin function definition
{
    ListNode* nodePtr = head;                                                                  //    We'll have to traverse the list so we start by making a new pointer and setting it to the first node in the list

    while (nodePtr != NULL)                                                                    //    while we haven't yet reached the bottom of the list...
    {
        ListNode* garbage = nodePtr;                                                           //    set pointer "garbage" to the current node
        nodePtr = nodePtr->next;                                                               //    move down to the next node
        delete garbage;                                                                        //    delete the previous node
    }
}
/*********************************************************************************************************************************************************
                                                    THIS MARKS THE END OF THE DESTRUCTOR
**********************************************************************************************************************************************************/




//template class LinkedList<char>;
template class LinkedList<string>;                                //    I don't know what this is, or why I needed it here, but I did need it...also, I need an adult...
//template class LinkedList<short>;
//template class LinkedList<int>;
//template class LinkedList<long>;
//template class LinkedList<long long>;
//template class LinkedList<float>;
//template class LinkedList<double>;
//template class LinkedList<long double>;