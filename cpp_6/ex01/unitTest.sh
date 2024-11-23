#!/bin/bash

EXECNAME="./Serializer" # Nom de l'exécutable à tester

# Rebuild the project
make re
clear
# Basic name tests
$EXECNAME "Alice"
$EXECNAME "Bob"
$EXECNAME "Charlie"
$EXECNAME "David"
$EXECNAME "Eve"

# Compound names
$EXECNAME "Jean-Luc"
$EXECNAME "Mary Jane"
$EXECNAME "O'Conner"
$EXECNAME "Anne-Marie"
$EXECNAME "Van der Meer"

# Names with special characters
$EXECNAME "Léa"
$EXECNAME "José"
$EXECNAME "Zoë"
$EXECNAME "Björk"
$EXECNAME "Muñoz"

# Edge cases
$EXECNAME ""
$EXECNAME "-"
$EXECNAME " "
$EXECNAME "123"
$EXECNAME "John123"
$EXECNAME "John Doe123"
$EXECNAME "@name"

# Long names
$EXECNAME "MaximilianAlexanderTheThird"
$EXECNAME "ThisIsAReallyLongNameToTestTheLimitsOfTheProgram"
$EXECNAME "AnotherExtremelyLongNameThatGoesOnAndOnAndOnWithoutEnd"

# Invalid or unexpected inputs
$EXECNAME "!@#$%^&*()"
$EXECNAME "NameWithTab	TabHere"
$EXECNAME "NameWith\nNewline"
$EXECNAME "Multiple    Spaces"
$EXECNAME "--invalid-name"
$EXECNAME "name.with.dots"

# Mixed cases
$EXECNAME "Alice123-Bob!"
$EXECNAME "  SpacesBefore"
$EXECNAME "SpacesAfter   "
$EXECNAME "   LeadingAndTrailingSpaces   "
$EXECNAME "UPPERCASE"
$EXECNAME "lowercase"
$EXECNAME "CamelCase"
$EXECNAME "snake_case"
$EXECNAME "kebab-case"

# Multiple arguments at once
$EXECNAME "Alice" "Bob" "Charlie"
$EXECNAME "Jean-Luc" "Mary Jane" "O'Conner"
$EXECNAME "Léa" "José" "Zoë" "Björk"
$EXECNAME "" "-" "123"

# Optional: Add a summary of tests
echo "All name-based tests completed. Please check the output for correctness."
make fclean
