# Rec_Evaluation

Get started:
Unzip "exerything (2).zip" go into the directory, where "start_congress_eval.sh" lies and execute it in a terminal with ./start_congress_eval.sh.


Additional Information:
- Within the datset folder you'll need the files "C.txt", "F.txt", "dAtoC.txt" and the directory "EvaluationResults", with the subdirectories "kUFLLocalSearch", "LP", "RecLocalSearch".
- Optional textfile "G.txt".
- C.txt: has all the numbers, corresponding to clients
- F.txt: has all the numbers, corresponding to facilities (Facilities have to be part of the client set and need to occupy the first numbers available, e.g. 500 facilities -> numbers are 0 to 499)
- dAtoC.txt: has at least the distances between all facilities and clients. If it isn't a full distance matrix, then "G.txt" has to be included in the directory.
- distances are seperated by commas and the line index corresponds to the client number -> First line, third distance in that line, corresponds to the distance between 0 and 2.
- G.txt: Containts the conection graph. Lines are as follows: <client's number>tab<neighbouring clients> (neighbouring clients are seperated by a comma.
- The algorithms will write their results in their respected directory, e.g. the LP algorithm will write a result into "<Dataset>/EvaluationResults/LP/".
