import templates, layout, jester

var screenshots = [1,2,3]

proc index*(request: PRequest): string =
    tmpli html"""
        <div>
            <ul>
                $for screnshot in screenshots {
                   <li>$screnshot</li>
                }
            </ul>
        </div>
        """

    return layout.layout("Screenshots", result)

proc save*(request: PRequest): string =
    writeFile("filename.png", request.formData.mget("images[]").body)
