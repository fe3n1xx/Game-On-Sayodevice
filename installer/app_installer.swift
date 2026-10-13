import Foundation

let fileManager = FileManager.default
var isDirectory: ObjCBool = false
var acceptedFileURL: URL?

print("Enter the file to add: ", terminator: "")

if let input = readLine() {
    if fileManager.fileExists(atPath: input, isDirectory: &isDirectory) {
        if isDirectory.boolValue {
            print("This path is a directory, not a script.")
        } else {
            acceptedFileURL = URL(fileURLWithPath: input)
            print("File existence verified")
        }
    } else {
        print("ERROR: NOT A VALID FILE")
    }
}

if let fileURL = acceptedFileURL {
    let fileNameWithoutExtension = fileURL.deletingPathExtension().lastPathComponent
    let fileInfoText = fileNameWithoutExtension + ".txt"

    let scriptsDirectory = URL(fileURLWithPath: "../scripts", isDirectory: true)
    let fileInfoTextPath = scriptsDirectory.appendingPathComponent(fileInfoText)

    print("What should your file be referred to as in the Software?: ", terminator: "")

    if let input = readLine() {
        do {
            try input.write(to: fileInfoTextPath, atomically: true, encoding: .utf8)
            print("File created successfully at \(fileInfoTextPath.path)")
        } catch {
            print("Failed to write file: \(error)")
        }
    }
}
