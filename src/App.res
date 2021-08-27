@react.component
let make = () => {
  let (teams: list<Team.t>, setTeams) = React.useState(() => list{
    ({name: "Mambas", captain: "Kobe Bryant"}: Team.t),
    {name: "Moses and the Mosets", captain: "Moses Samuel"},
    {name: "The Mini Mikes", captain: "Michael Sadaghyani"},
  })

  let (shouldShowWaitTime, setShouldShowWaitTime) = React.useState(() => false)

  let addNewTeam = (team: Team.t) => setTeams(prevTeams => list{team, ...prevTeams})

  <main>
    <TeamCreator update=addNewTeam renderWaitTime=setShouldShowWaitTime />
    <TeamList teams />
    <WaitTime queue=teams shouldShowWaitTime />
    <GameOver setTeams />
  </main>
  /* This is broken for some reason. I believe it's an issue with the import. */
  /* <QRCode dataToEncode="MosesSupposes rocks" /> */
}
