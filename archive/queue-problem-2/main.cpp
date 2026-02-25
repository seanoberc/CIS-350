// #include <iostream>
// #include <string>
// #include "Queue.h"
//
// using namespace std;
//
// /*
//  * `main()` method for empulating the print spooler
//  */
//
// int main(int argc, char *argv[]) {
//     // 1. create an instance of a queue for printing strings
//     Queue<string> printSpooler;
//
//     // 2. add jobs to print queue
//     cout << "Loading jobs into the queue..." << '\n';
//     printSpooler.enqueue("Annual_Report.docx");
//     printSpooler.enqueue("Family_Photo.png");
//     printSpooler.enqueue("Data_Sheet.xlsx");
//
//     // 3.  print the current size of the queue and show the job at the front using `peek()`
//     cout << "Jobs currently queued:" << printSpooler.size() << '\n';
//     cout << "Next print job:" << printSpooler.peek() << "\n\n";
//
//     // 4. process two jobs from the print queue
//     for (int i = 0; i < 2; i++) {
//         if (!printSpooler.isEmpty()) {
//             cout << "Processing job: " << printSpooler.dequeue() << '\n';
//             cout << "Jobs remaining: " << printSpooler.size() << '\n';
//         } else {
//             cout << "Process complete." << '\n';
//             break;
//         }
//     }
//
//     // 5. add two new jobs to the queue
//     cout << "Adding two new jobs..." << '\n';
//     printSpooler.enqueue("Essay_Outline.pdf");
//     printSpooler.enqueue("Rental_VINs.csv");
//
//     // 6. Print the new size of the queue and show the current job at the front.
//     cout << "Jobs queued:" << printSpooler.size() << '\n';
//     cout << "Current job:" << printSpooler.peek() << "\n\n";
//
//     // 7. process remaining jobs in queue
//     while (!printSpooler.isEmpty()) {
//         cout << "Processing remaining jobs: " << printSpooler.dequeue() << '\n';
//     }
//
//     // 8. verify the queue is empty
//     cout << "Is the queue empty? ";
//     if (printSpooler.isEmpty()) {
//         cout << "Yes (True)" << '\n';
//     } else {
//         cout << "No (False)" << '\n';
//     }
//     cout << '\n';
//
//     // // 9. demonstrate underflow error handling
//     // try {
//     //     printSpooler.dequeue();
//     // } catch (underflow_error& e) {
//     //     cerr << "Exception caught: " << e.what() << '\n';
//     // }
//
//     // 9. demonstrate underflow error handling
//     try {
//         cout << "Attempting to dequeue from an empty queue..." << '\n';
//         printSpooler.dequeue();
//     } catch (const underflow_error& e) {
//         cerr << "Exception caught: " << e.what() << '\n';
//     }
// }
