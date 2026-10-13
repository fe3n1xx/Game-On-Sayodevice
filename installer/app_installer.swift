import Foundation

let fileManager = FileManager.default
var isDirectory: ObjCBool = false
var acceptedFile = false

print("Enter the file to add: ", terminator: "")

if let input = readLine() {
    if fileManager.fileExists(atPath: input, isDirectory: &isDirectory) {
        if isDirectory.boolValue {
            print("This path is a directory, not a script.")
        } else {
            acceptedFile = true
            print("File existence verified")
        }
    } else {
        print("ERROR: NOT A VALID FILE")
    }
}

if acceptedFile {
    // Continue with the accepted file
}
