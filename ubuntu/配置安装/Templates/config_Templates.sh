#!/bin/bash
project_path=${HOME}/Templates
echo -e "#include<iostream>\n\nusing namespace std;\n\nint main(){\n\n\n    return 0;\n}">$project_path/c++.cpp;
echo -e "#!/usr/bin/python3\n\nif __name__==\"__main__\":\n    pass">$project_path/python3.py;
echo -e "#!/bin/bash">$project_path/shell.sh;
chmod +x $project_path/python3.py $project_path/shell.sh
echo -e "">$project_path/txt.txt;
echo -e "">$project_path/README.md;
