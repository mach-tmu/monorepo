
export type SensorInfo = {
    name: string;
    unit: string;
    min: number;
    max: number;
};

export type SystemInfo = {
    sensors: SensorInfo[];
    valves: string[];
    sequences: string[];
};

export type DataFile = {
    name: string;
    size: number;
    date_created: Date;
    content?: JSON;
}
