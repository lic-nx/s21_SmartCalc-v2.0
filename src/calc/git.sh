#!bin/bash
git add .
git commit -m "$USER : $(date +"%H:%M %d/%m/%Y")"
git push origin develop