import jester, future, asyncdispatch

proc save(request: PRequest): string =
    writeFile("filename.png", request.formData.mget("images[]").body)

routes:
  post "": resp save(request)

runForever()
