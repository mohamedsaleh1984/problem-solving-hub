#!/bin/bash

# Print a message to confirm deletion
echo "Searching for .vscode and build folders..."

# Find and delete all `.vscode` directories
find . -type d -name ".vscode" -exec rm -rf {} +

# Find and delete all `build` directories
find . -type d -name "build" -exec rm -rf {} +

echo "Cleanup complete. All .vscode and build folders have been removed."

