import Foundation
import Darwin

let fileManager = FileManager.default
var isDirectory: ObjCBool = false
var acceptedFileURL: URL?
var fileDestination: URL?

print("Enter the file to add: ", terminator: "")

if let input = readLine() {
    if fileManager.fileExists(atPath: input, isDirectory: &isDirectory) {
        if isDirectory.boolValue {
            print("This path is a directory, not a script.")
            print("Ending Script")
            exit(0)
        } else {
            acceptedFileURL = URL(fileURLWithPath: input)
            fileDestination = URL("../scripts")
            print("File existence verified")
            try FileManager.default.copyItem(at: acceptedFileURL, to: fileDestination) {
                print("File merged to ../scripts")
            } catch {
                print("File failed to merge")
                print("Ending Script")
                exit(0)
            }
        }
    } else {
        print("ERROR: NOT A VALID FILE")
        print("Ending Script")
        exit(0)
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
            print("Ending Script")
            exit(0)
        }
    }
}
print("Script has been completed")
print("Ending Script")
exit(0)

