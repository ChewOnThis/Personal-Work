import requests # pip install requests
from bs4 import BeautifulSoup # pip install requests beautifulsoup4

def parse_google_doc(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    content = soup.get_text(separator='\n').strip()
    lines = content.split('\n')
    max_x = 0
    max_y = 0
    
    characters = []
    data_lines = []
    coordinates_line_count = 0

    for line in lines:
        line = line.strip()

        
        if line.isdigit():
            coordinates_line_count += 1
            data_lines.append(line)

      
        elif len(line) == 1 and not line.isalnum():
            data_lines.append(line)

  
    for i in range(0, len(data_lines), 3):
        if i + 2 < len(data_lines):
            x = int(data_lines[i].strip())
            char = data_lines[i + 1].strip()
            y = int(data_lines[i + 2].strip())

            characters.append((x, y, char))
            
          
            max_x = max(max_x, x)
            max_y = max(max_y, y)

 
    grid = [[' ' for _ in range(max_x + 1)] for _ in range(max_y + 1)]
    
  
    for x, y, char in characters:
        grid[y][x] = char
    
#printing in format
    for row in grid:
        print(''.join(row))


url = "https://docs.google.com/document/d/e/2PACX-1vSHesOf9hv2sPOntssYrEdubmMQm8lwjfwv6NPjjmIRYs_FOYXtqrYgjh85jBUebK9swPXh_a5TJ5Kl/pub"
parse_google_doc(url)
