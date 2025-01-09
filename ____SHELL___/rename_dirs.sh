#!/bin/bash

#Explanation:
#*/: Selects all directories.
#tr '[:upper:]' '[:lower:]': Converts the directory name to lowercase.
#tr ' ' '_': Replaces spaces with underscores.
#mv "$dir" "$new_dir": Renames the directory.
#This should work effectively for most directory structures!


# Loop through all directories in the current directory
for dir in */; do
  # Remove trailing slash
  dir=${dir%/}
  # Convert folder name to lowercase and replace spaces with underscores
  new_dir=$(echo "$dir" | tr '[:upper:]' '[:lower:]' | tr ' ' '_')
  # Rename the directory if the new name is different
  if [ "$dir" != "$new_dir" ]; then
    mv "$dir" "$new_dir"
  fi
done



