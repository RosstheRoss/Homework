function valid = filename_test(fileLoc, tar_name, username, hwNumber, numOfAssignment)
% fileLoc is the folder where you stored your tar file, you can find it by cd into the folder and 
% type "pwd" in terminal, don't forget to put it in quote like this:
% 'fileLoc',  because it's a string!

% tar_name is the name of the tar file you want to test, it should also be
% a string, so again, don't forget the quote!

% username is your X500 ID, also a string!

% hwNumber is the number of assignment, "HW hwNumber". input just a number here

% numOfAssignment is how many problems are there in this assignment, also a number

% Example command:
% filename_test('/home/jc/Desktop', 'hw1_yuanx320.tgz', 'yuanx320', 1, 2);

%  -----------------How to use:-------------------
%  -----------------------------------------------
% - Upload this file to CSE machine
% - Log into CSE machine and open terminal
% - In terminal, cd into the folder where you store this matlab code
% - Type "matlab", wait for matlab open
% - In the command window of matlab, type in the command you generated 
%   following the instructions up there


% ----------------Expected output------------------
% -------------------------------------------------
% After running the tester,
% in the command window of matlab you will see some output
% Modify your file name accoddingly until you see "File name test passed!"
% 

% tar_name = strcat(sprintf('hw%d_',hwNumber), username, '.tgz');
cd(fileLoc);
untar(tar_name);

folder_name = sprintf('hw%d_directory', hwNumber);
file_name = cell(numOfAssignment);
a = 'A';
for i = 1:numOfAssignment
    b = char(a+i-1);
    file_name{i} = strcat(username, sprintf('_HW%d', hwNumber), b, '.cpp');
end


mkdir temp;
command1 = strcat('tar -xzvf ', tar_name, ' -C temp/');
system(command1);
cd temp;
a = exist(folder_name);
valid = true;
        
if a == 7
    cd(folder_name);
    filecpp = dir('*.cpp');
    if ~isempty(filecpp)
        for i = 1:numOfAssignment
            if strcmp(filecpp(i).name, file_name{i, 1}) == false
                valid = false;
            end
        end
        
        if valid == 0
            fprintf(".cpp file name incorrect! Example: yuanx320_HW2A.cpp\n");
        else
            fprintf("File name test passed!\n");
        end
        
    else
        fprintf("No .cpp file included in this directory.\n");
    end
    cd ..;
    
    
            
    
else
    fprintf("Wrong folder name, it should be hw2_directory.\n");
end

cd ..;
rmdir temp s;   



end