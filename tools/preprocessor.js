const fs = require('fs');

function save(origin_file, data) {
    const file = origin_file.replace('.src.json', '.json');
    fs.writeFileSync(file, JSON.stringify(data, null, 2));
    console.log(`Saved processed file: ${file}`);
}

function processPalette(palette, data) {
    for (const [key, value] of Object.entries(data)) {
        if (typeof value === 'string' && value.startsWith('$')) {
            const colorKey = value.replace('$palette.', '');
            if (palette.hasOwnProperty(colorKey)) {
                data[key] = palette[colorKey];
            }
        } else if (typeof value === 'object' && value !== null) {
            data[key] = processPalette(palette, value);
        } else if (Array.isArray(value)) {
            data[key] = value.map(item => {
                return processPalette(palette, item);
            });
        }  
    }
    return data;
}

function main() 
{
    var args = process.argv.slice(2);
    if (args.length === 0) {
        return;
    }
    const file = args[0];
    console.log(`Processing file: ${file}`);
    const jsonString = fs.readFileSync(file, 'utf-8');
    let data = JSON.parse(jsonString);

    const palette = data['palette'];
    if (palette) {
        data = processPalette(palette, data);
    }

    save(file, data);
}

main();