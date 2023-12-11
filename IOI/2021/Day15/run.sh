mkfifo fifoContestantToManager
mkfifo fifoManagerToContestant
cp $2 input.txt
# g++ -o manager manager.cpp
# echo "Compling $1"
# g++ -o contestant $1
# echo "Running $1" 
time ./manager fifoContestantToManager fifoManagerToContestant >score.txt | ./contestant <fifoManagerToContestant >fifoContestantToManager
echo "Score = $(cat score.txt)"
# rm contestant
# rm manager
rm fifoContestantToManager
rm fifoManagerToContestant