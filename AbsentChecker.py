import string

# Open files for reading
try:
    all_ids_file = open("EcoAll.txt", "r")
    garbage_ids_file = open("Echogarbage.txt", "r")
except IOError:
    print("Error: Unable to open file.")
    exit()

# Read all IDs from all_ids.txt into a list
all_ids = []
for line in all_ids_file:
    all_ids.append(line.strip())

all_ids_file.close()

# Read all IDs from garbage_ids.txt into a list
garbage_ids = []
for line in garbage_ids_file:
    # Extract 9-digit student IDs from the line
    ids_in_line = [id.translate(str.maketrans('', '', string.punctuation)) for id in line.split() if len(id) == 9 and id.isdigit()]
    garbage_ids += ids_in_line

garbage_ids_file.close()

# Find the missing IDs
missing_ids = set(all_ids) - set(garbage_ids)

# Print the missing IDs
print("Absent students:")
for i, student_id in enumerate(missing_ids, 1):
    print(f"{i} {student_id}")
