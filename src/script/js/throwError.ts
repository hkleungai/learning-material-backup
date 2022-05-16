const throwError = (error: string): never => {
  alert(error);
  throw new Error(error);
}
