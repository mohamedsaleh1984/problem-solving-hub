#!/bin/bash

# Check if both folder name and file name are provided
if [ $# -ne 1 ]; then
  echo "Usage: $0 <folder_name>"
  exit 1
fi

# Get folder and file names from arguments
FOLDER_NAME=$1
FILE_NAME="$1.cpp"

# Create the folder
mkdir -p "$FOLDER_NAME"

# Create the .cpp file inside the folder
CPP_FILE="$FOLDER_NAME/$FILE_NAME"
echo "$CPP_FIEL"

# Write the C++ template to the file
cat <<EOL > "$CPP_FILE"
#include "../common.h"

class Solution {
public:
  
};

int main() {
    
    return 0;
}
EOL

# Provide feedback to the user
echo "Folder '$FOLDER_NAME' and file '$CPP_FILE' created successfully!"
