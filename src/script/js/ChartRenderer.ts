// TODO: Append typing, maybe by commit hooks.
import BaseRenderer, { BaseProps } from 'https://hkleungai.github.io/mini-web-component/BaseRenderer.js';
// TODO: Append typing, maybe by commit hooks.
// @ts-ignore
import vis from 'https://visjs.github.io/vis-network/dist/vis-network.esm.js';

interface ChartRendererProps extends BaseProps {

}

// @ts-ignore
const isFirefox = typeof InstallTrigger !== 'undefined';

class ChartRenderer extends BaseRenderer<ChartRendererProps> {
  constructor() {
    super('Chart');
  }
  protected build(): this {
    this.innerHTML = (
      /* html */`
      <div>
        ${isFirefox ? 'Sorry to disappoint. This won\'t work in Firefox.': '<div id="myChart">'}
      </div>
      `
    );
    return this;
  }
  protected attachEvent(): this {
    if (isFirefox) {
      return this;
    }
    const highlightBackground = '#008000';
    const highlightText = '#ffffe0';
    const nodes = new vis.DataSet([
      { id: 1, label: "COMP 100" },
      { id: 2, label: "COMP 200" },
      { id: 3, label: "COMP 300",
        font: {
          color: highlightText,
        },
        color: {
          background: highlightBackground,
          highlight: {
            background: highlightBackground,
          },
          hover: {
            background: highlightBackground,
          }
        }
      },
      { id: 4, label: "COMP 400" },
      { id: 5, label: "COMP 500" },
    ]);

    // create an array with edges
    const edges = new vis.DataSet([
      { from: 1, to: 2 },
      { from: 2, to: 3 },
      { from: 3, to: 4 },
      { from: 3, to: 5 },
      // { from: 3, to: 3 },
    ]);

    // create a network
    const container = this.fragment.getElementById("myChart");
    const data = { nodes, edges };
    const normalBackground = '#ffffe0';
    const normalText = '#008000';
    const options = {
      edges: {
        // font: '20px arial red',
        arrows: {
          to: true,
          middle: true,
          // from: true,
        }
      },
      nodes: {
        font: {
          size: 16,
          color: normalText,
        },
        color: {
          background: normalBackground,
          border: normalText,
          highlight: {
            background: normalBackground,
            border: normalText,
          },
          hover: {
            background: normalBackground,
            border: normalText,
          }
        },
        shape: 'box'

        // value: 2,
        // scaling: 'text',
      },
    };
    const network = new vis.Network(container, data, {});
    network.setOptions(options);

    // @ts-ignore
    // container!.querySelector('canvas').style['background'] = '#77ff69'
    container!.querySelector('canvas').style['background'] = '#ffff69'

    return this;
  }
}

// console.log({ Graph })
// console.log({ Graph: new Graph.Graph() })

export default new ChartRenderer();
