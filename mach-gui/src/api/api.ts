import { SystemInfo, DataFile } from "./apiTypes";

export function getSystemInfo() : SystemInfo {
    // TODO issue #2
    return {
        "sensors": [
            {
                "name": "T1",
                "unit": "°C",
                "min": 0,
                "max": 100
            },
            {
                "name": "T2",
                "unit": "°C",
                "min": 0,
                "max": 100
            }
        ],
        "valves": [
            "P20", "P30", "LC"
        ],
        "sequences": [
            "Launch", "Sequence One", "Sequence Two"
        ]
    };
}

export function getDataFiles() : DataFile[] {
    // TODO issue #4
    return [
        {
            "name": "file1.csv",
            "size": 1024,
            "date_created": new Date()
        },
        {
            "name": "file2.csv",
            "size": 2048,
            "date_created": new Date()
        }
    ];
}

export function getDataFile(name: string) : string {
    // TODO issue #4
    console.log("Getting data file: " + name);
    return "{}";
}

export function downloadDataFile(name: string) : void {
    // TODO issue #4
    const data = getDataFile(name);
    console.log("Downloading file: " + name + " with data: " + data);
}
