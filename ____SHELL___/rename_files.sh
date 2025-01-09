#!/bin/bash
# Loop through all .cpp and .c files in the current directory and subdirectories
find . -type f \( -name "*.cpp" -o -name "*.c" \) | while read file; do
  # Extract the directory and filename separately
  dir=$(dirname "$file")
  base=$(basename "$file")
  
  # Convert filename to lowercase and replace spaces with underscores
  new_base=$(echo "$base" | tr '[:upper:]' '[:lower:]' | tr ' ' '_')
  
  # Rename the file if the new name is different
  if [ "$base" != "$new_base" ]; then
    mv "$dir/$base" "$dir/$new_base"
  fi
done
